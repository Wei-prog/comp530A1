
#ifndef BUFFER_MGR_C
#define BUFFER_MGR_C

#include "MyDB_BufferManager.h"
#include "MyDB_LRU.h"
#include <string>
#include <list>
#include <stlib.h>
#include <iostream>
#include <fstream>

using namespace std;

<<<<<<< HEAD
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
=======
MyDB_PageHandle MyDB_BufferManager :: getPage (MyDB_TablePtr, long) {	
	MyDB_PagePtr page;
	this->LRU.refer(page);
	return nullptr;
}
>>>>>>> f5e941b241065777177538ecf0442ac5af1c6143

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
	MyDB_PagePtr page;
	this->LRU.refer(page);
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
	long sizeofCache;
	// Create a LRU Cache
	this->LRU  = LRUCache::cache(sizeofCache);
}

MyDB_BufferManager :: ~MyDB_BufferManager () {
	// TODO: Empty the LRU list 
	
}

// Create a LRU Cache
LRUCache::LRUCache(long n){
    this->size = n;
}

//TODO: Refers key x with in the LRU cache
void LRUCache::refer(MyDB_PagePtr x){
	// not present in cache
	if (map.find(x) == map.end()) {
		// cache is full
		if (LRU.size() == this->size) {
			// delete least recently used element
			MyDB_PagePtr last = LRU.back();

			// Pops the last element
			LRU.pop_back();

			// Erase the last
			map.erase(last);
		}
	}
	// present in cache
	else
		LRU.erase(map[x]);
	// update reference
	LRU.push_front(x);
	map[x] = LRU.begin();
}



#endif


