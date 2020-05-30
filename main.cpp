#include <iostream>
#include "include/DBInterface.h"
#include "include/DBBuilder.h"

using namespace std;

int main()
{
    DBInterface *obj;
    DBBuilder buildobj;

    obj=buildobj.buildDB();
    if(obj!=NULL){
    cout << "created DB!" <<obj->openDB() << endl;
    cout << "setValues DB!" <<obj->setValues() << endl;
    cout << "getValues DB!" <<obj->getValues() << endl;
    cout << "destroy DB!" <<obj->closeDB() << endl;
    }
    else{
    cout << "Current DB operations not supported" <<endl;
    }
    return 0;
}
