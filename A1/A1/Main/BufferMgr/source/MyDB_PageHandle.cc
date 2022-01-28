
#ifndef PAGE_HANDLE_C
#define PAGE_HANDLE_C

#include <memory>
#include "MyDB_PageHandle.h"

void *MyDB_PageHandleBase :: getBytes () {
	return this->page->getBytes();
}

void MyDB_PageHandleBase :: wroteBytes () {
	this->page->wroteBytes(); // TODO: Check the way call the method
}

MyDB_PageHandleBase :: ~MyDB_PageHandleBase () {
	this->page->decRef(); // TODO: Check the way call this method
}


// Self added code

// We will need a constructor when add new PageHandleBase.
MyDB_PageHandleBase :: MyDB_PageHandleBase(MyDB_Pageptr page){
	this->page = page
	this->page->incRef();
}

#endif

