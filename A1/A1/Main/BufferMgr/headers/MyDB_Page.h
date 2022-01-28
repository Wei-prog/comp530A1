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

    // Constructure
    MyDB_Page(MyDB_lookTablePtr lookTable, MyDB_BufferManager &pos,size_t offset); // TODO: Arguments remain to be checked
    
    // Destructor
    ~MyDB_Page ();

    // Get the Bytes from the page object
	void *getBytes ();

    // Set page to a dirty page if it is
	void setDirty ();

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
