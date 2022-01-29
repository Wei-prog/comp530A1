
#ifndef PAGE_HANDLE_C
#define PAGE_HANDLE_C

#include <memory>
#include "MyDB_PageHandle.h"

void *MyDB_PageHandleBase :: getBytes () {
	//update of LRU here, then
	//if(this->pagePtr is in buffer){
		//this->pagePtr->updateLRU(this->pagePtr);
	//}
	//same logic with get page, write there to reduce code lines
	return this->page->getBytes();
}

void MyDB_PageHandleBase :: wroteBytes () {
	this->page->setDirty(true);
	this->page->wroteBytes(); 
}

MyDB_PageHandleBase :: ~MyDB_PageHandleBase () {
	this->page->decRef(); 
}


// Self added code

// We will need a constructor when add new PageHandleBase.
MyDB_PageHandleBase :: MyDB_PageHandleBase(MyDB_Pageptr page){
	this->page = page
	this->page->incRef();
}

#endif

