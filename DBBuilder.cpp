#include <iostream>
#include <string>
#include "include/DBBuilder.h"
#include "include/DBInterface.h"
#include "include/DBSQLite.h"

using namespace std;

DBInterface* DBBuilder::buildDB(){
#ifdef _WIN64
    cout<<"DB for Windows"<<endl;
    return new DBSQLite();
#else
    cout<<"DB for linux"<<endl;
    return NULL;
#endif
}
