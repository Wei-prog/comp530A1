
#ifndef LRU_C
#define LRU_C

#include "MyDB_LRU.h"

using namespace std;

MyDB_LRUCache::LRUCache(){
    this->LRU = new std::list<MyDb_Pageptr>();
    
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