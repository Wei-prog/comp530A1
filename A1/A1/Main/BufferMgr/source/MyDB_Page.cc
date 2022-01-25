#ifndef PAGE_C
#define PAGE_C

#include "MyDB_BufferManager.h"
#include "MyDB_Page.h"

using namespace std;
MyDB_Page ::MyDB_Page(MyDB_lookTablePtr lookTable, MyDB_BufferManager &pos,size_t offset){
    this->pos=pos;
    this->lookTable=looktable;
    this->bytes = nullptr;
    this->ref = 0;
    this->dirty = false;
    this->pin = false;
    this->offset = offset;
}

MyDB_Page::~MyDB_Page(){}

void *getBytes (){
 return this->byte;
}
void setDirty (){
    this->dirty = true;
}
void MyDB_Page::incRef(){
    this->ref=ref+1;
}
void MyDB_Page:: decRef(){
    //call destroy page when applicable
    this->ref -=1;
}
void setBytes(void* byteVal){
    this->byte = byteVal;
}
bool isDirty(){
    return this->dirty;
}
bool isPinned(){
    return this->pin;
}


#endif