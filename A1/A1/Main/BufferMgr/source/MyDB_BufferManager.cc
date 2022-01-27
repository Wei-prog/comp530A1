
#ifndef BUFFER_MGR_C
#define BUFFER_MGR_C

#include "MyDB_BufferManager.h"
#include <string>
#include <list>
#include <stlib.h>
#include <iostream>
#include <fstream>

using namespace std;

//constructor, we need pageSize, numPages in buffer, and temp location
//we want to create memory buffer, LRU list and an empty lookup table
MyDB_BufferManager::MyDB_BufferManager(size_t page_size,size_t numPages,string tempFile){	
	this->page_size = page_size;
	this->numPages = numPages;
	this->tempFile = tempFile;
	file.open(tempFile,fstream::out)
	for (size_t i =0 ; i<numPages;i++){
		this->memBuffer.push_back((void*)malloc(page_size));
	}
	//there is no need to initialize look up table or is there?
	this->lookupTable=std::map<pair<MyDB_TablePtr,long>, MyDB_Pageptr>();
	//the LRU linked list, use stl list  

}
//
MyDB_PageHandle MyDB_BufferManager :: getPage (MyDB_TablePtr whichTable, long i) {
	//the pos of a current page should be whichtable address+i 
	//we want to find a page, using 
	//first tableptr not null
	if (whichTable == nullptr){
		std::cout<< "When getting page, table pointer is null."<<endl;
		exit(1);
	}
	//if no such page found, create and push into table, also LRU and memory buffer, how do I do it?
	MyDB_PageHandle naPage =  new 
	return ;		
}
//anonymous
MyDB_PageHandle MyDB_BufferManager :: getPage () {
	return nullptr;		
}

MyDB_PageHandle MyDB_BufferManager :: getPinnedPage (MyDB_TablePtr, long) {
	return nullptr;		
}

MyDB_PageHandle MyDB_BufferManager :: getPinnedPage () {
	return nullptr;		
}

void MyDB_BufferManager :: unpin (MyDB_PageHandle unpinMe) {
}

MyDB_BufferManager :: MyDB_BufferManager (size_t, size_t, string) {
}

MyDB_BufferManager :: ~MyDB_BufferManager () {
}
	
#endif


