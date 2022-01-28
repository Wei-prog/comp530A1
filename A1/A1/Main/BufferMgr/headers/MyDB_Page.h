#ifndef PAGE_H
#define PAGE_H
#include <string>
#include <memory>

//page are building blocks for buffer accessed by handler
//property includes: 
//pinned, dirty, byte, refcount, temp?->to a single file
 using namespace std;
class MyDB_Page;
typedef shared_ptr <MyDB_Page> MyDB_Pageptr;
class MyDB_PageHandleBase {

public:

	void *getBytes ();
	void setDirty ();
	//I don't think this will ever used
    //maybe when destroy a page
    MyDB_Page(MyDB_TablePtr lookTable, MyDB_BufferManager &pos,size_t offset);
    ~MyDB_Page ();
    void incRef();
    void decRef();
    void setBytes();
    bool isDirty();
    bool isPinned();

	// FEEL FREE TO ADD ADDITIONAL PUBLIC METHODS

private:
    MyDB_BufferManager &pos;
    MyDB_lookTablePtr lookTable;
    bool dirty;
    bool pin;
    void *bytes;
    int ref;
    int offset;

	// YOUR CODE HERE
};

#endif
