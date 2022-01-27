
#ifndef BUFFER_MGR_C
#define BUFFER_MGR_C

#include "MyDB_BufferManager.h"
#include "MyDB_LRU.h"
#include <string>

using namespace std;

MyDB_PageHandle MyDB_BufferManager :: getPage (MyDB_TablePtr, long) {	
	MyDB_PagePtr page;
	this->LRU.refer(page);
	return nullptr;
}

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


