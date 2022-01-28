#ifndef PAGE_H
#define PAGE_H

#include "../../Catelog/headers/MyDB_Table.h"
#include <string>
#include <memory>

//page are building blocks for buffer accessed by handler
//property includeds: 
//pinned, dirty, byte, refcount, temp?->to a single file
 using namespace std;
class MyDB_Page;
typedef shared_ptr <MyDB_Page> MyDB_Pageptr;
class MyDB_PageHandleBase {

public:

    // Constructure
    MyDB_Page(MyDB_TablePtr lookUpTable, MyDB_BufferManager &pos, size_t offset); // TODO: Arguments remain to be checked
    
    // Destructor
    ~MyDB_Page ();

    // Get the Bytes from the page object
	void *getBytes ();

    // Set page to a dirty page if it is
	void setDirty ();

    // Increase the number of the PageHandleBase to the Page Object
    void incRef();
    // Decrease the number of the PageHandleBase to the Page Object
    void decRef();

    // Set the bytes
    void setBytes(void* byteVal);

    // Check the page is dirty or not
    bool isDirty();

    // Check the page is pinned or not
    bool isPinned();

    // Pin the page
    void setPin(bool pinned);

    // Write the bytes into the page.
    // TODO: Does this need to be change to pointer to call? 
    void wroteBytes();


	// FEEL FREE TO ADD ADDITIONAL PUBLIC METHODS

private:

    // Link to the buffer pool
    MyDB_BufferManager &pos;

    // The look table
    MyDB_TablePtr lookUpTable;

    bool dirty;
    bool pin;
    void *bytes;
    int ref;
    size_t offset;

	// YOUR CODE HERE
};

#endif
