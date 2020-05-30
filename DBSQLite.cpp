#include <iostream>
#include <string>
#include "include/DBSQLite.h"

using namespace std;

int DBSQLite::openDB(){
    exit = 0;
    exit = sqlite3_open("example.db", &DB);

    if (exit) {
        cerr << "Error open DB " << sqlite3_errmsg(DB) <<  endl;
        return (-1);
    }
    else
        cout << "Opened Database Successfully!" <<  endl;

    return (0);
}
int DBSQLite::closeDB(){
    sqlite3_close(DB);
    cout<<"Closed Database Successfully!"<< endl;
    return (0);
}
int DBSQLite::setValues(){
    string sql1 = "CREATE TABLE PERSON("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "NAME           TEXT    NOT NULL, "
                      "SURNAME          TEXT     NOT NULL, "
                      "AGE            INT     NOT NULL, "
                      "ADDRESS        CHAR(50), "
                      "SALARY         REAL );";
    char* messaggeError;
    exit = 0;
    exit = sqlite3_exec(DB, sql1.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        cerr << "Table Already Exist" <<  endl;
        sqlite3_free(messaggeError);
    }
    else{
        cout << "Created Table Successfully!" <<  endl;
    }

     string sql2("INSERT INTO PERSON VALUES(1, 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);"
               "INSERT INTO PERSON VALUES(2, 'BILL', 'ALLEN', 20, 'SEATTLE', 300.22);"
               "INSERT INTO PERSON VALUES(3, 'PAUL', 'JOBS', 24, 'SEATTLE', 9900.0);");

    exit = sqlite3_exec(DB, sql2.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        cerr << "Error Insert" <<  endl;
        sqlite3_free(messaggeError);
    }
    else
        cout << "Records created Successfully!" <<  endl;
    return (0);
}

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);

    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

int DBSQLite::getValues(){
    exit = sqlite3_open("example.db", &DB);
    string data("CALLBACK FUNCTION");

    string sql("SELECT * FROM PERSON;");
    if (exit) {
        cerr << "Error open DB " << sqlite3_errmsg(DB) <<  endl;
        return (-1);
    }
    else
        cout << "Opened Database Successfully!" <<  endl;

    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL);

    if (rc != SQLITE_OK)
        cerr << "Error SELECT" << endl;
    else {
        cout << "Operation OK!" << endl;
    }
    return 1;
}
