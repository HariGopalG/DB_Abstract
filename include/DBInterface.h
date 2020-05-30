#ifndef DBINTERFACE_H_INCLUDED
#define DBINTERFACE_H_INCLUDED

class DBInterface{
public:
    virtual int openDB()=0;
    virtual int closeDB()=0;
    virtual int setValues()=0;
    virtual int getValues()=0;
};

#endif // DBINTERFACE_H_INCLUDED
