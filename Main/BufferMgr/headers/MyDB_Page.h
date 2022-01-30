
#ifndef PAGE_H
#define PAGE_H

#include "../../Catalog/headers/MyDB_Table.h"
#include <string>
#include <memory>

//page are building blocks for buffer accessed by handler
//property includeds: 
//pinned, dirty, byte, refcount, temp?->to a single file
using namespace std;
class MyDB_Page;
typedef shared_ptr <MyDB_Page> MyDB_Pageptr;
class MyDB_BufferManager;

class MyDB_Page {
    public:
        // Constructure
        MyDB_Page(MyDB_TablePtr whichTable, MyDB_BufferManager &pos, size_t offset);
        // Destructor
        ~MyDB_Page ();
        // Get the Bytes from the page object
        void *getBytes ();
        // Increase the number of the PageHandleBase to the Page Object
    // Write the bytes into the page.
        // TODO: Does this need to be change to pointer to call? 
        void wroteBytes();
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

        void *bytes;
        size_t offset;

        // FEEL FREE TO ADD ADDITIONAL PUBLIC METHODS

    private:
        // YOUR CODE HERE
        // Link to the buffer pool
        MyDB_BufferManager &pos;

        // The look table
        MyDB_TablePtr lookUpTable;

        bool dirty;
        bool pin;

        int ref;



};

#endif
