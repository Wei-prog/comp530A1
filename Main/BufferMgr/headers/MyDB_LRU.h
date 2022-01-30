#ifndef MyDB_LRU_H
#define MyDB_LRU_H
#include <bits/stdc++.h>
#include "MyDB_Page.h"
using namespace std;
 
class LRUCache {
    // store keys of cache
private:
    std::list<MyDB_Pageptr> LRU;
    void removeNode();
    // size of cache, we don't need
    
    // store references of key in cache
    //unordered_map<MyDB_PagePtr, list<MyDB_Pageptr>::iterator> map;
    
public:
    // for now no parameter becuase the buffer manager holds the thing, all we need is a start point ptr
    LRUCache();
    ~LRUCache();
    void refer(MyDB_Pageptr);
    void findNode();
    void updateList();
    
    // //LRU Opeartions

	// // Return the least recent used element in the LRU (tail)
	// MyDB_PagePtr getTail();

	// // Insert to the most recently used position of the element in the LRU (head)
	// void insertToHead();

	// // Delete and return the certain node in the list.
	// MyDB_PagePtr remove(MyDB_PagePtr page);
};

#endif