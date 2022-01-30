
#ifndef PAGE_C
#define PAGE_C

#include "../headers/MyDB_Page.h"
#include "../headers/MyDB_BufferManager.h"


using namespace std;
// Constructure
MyDB_Page::MyDB_Page(MyDB_TablePtr lookUpTable, MyDB_BufferManager &pos, size_t offset){
    this->pos=pos;
    this->lookUpTable=lookUpTable;
    this->bytes = nullptr;
    this->ref = 1;
    this->dirty = false;
    this->pin = false;
    this->offset = offset;
}

// Destructor
// MyDB_Page::~MyDB_Page(){}

/*All set function goes here*/
void setDirty (){
    this->dirty = true;
}
void setBytes(void* byteVal){
    this->byte = byteVal;
}
void setPin(bool pinned){
    this->pin = pinned;
}

// Increase the number of the PageHandleBase to the Page Object
void MyDB_Page::incRef(){
    this->ref=this->ref+1;
}
// Decrease the number of the PageHandleBase to the Page Object
void MyDB_Page:: decRef(){
    //call destroy page when applicable
    this->ref -=1;
    if(this->ref == 0){
        // TODO: Call the method to kill the page
    }
}

/*All return function goes here*/

void *getBytes(){
    return this->byte; // TODO: Still needs to check this function
}
bool isDirty(){
    return this->dirty;
}
bool isPinned(){
    return this->pin;
}
// There are something on the page.
void wroteBytes(){
    this->dirty = true;
}
MyDB_TablePtr getParentTable(){
    return this->lookUpTable;
}

#endif