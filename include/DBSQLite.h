#ifndef DBSQLITE_H_INCLUDED
#define DBSQLITE_H_INCLUDED
#include "DBInterface.h"
#include "sqlite3.h"

class DBSQLite: public DBInterface{
public:
    int openDB();
    int closeDB();
    int setValues();
    int getValues();
private:
    sqlite3* DB;
    int exit;
};


#endif // DBSQLITE_H_INCLUDED
