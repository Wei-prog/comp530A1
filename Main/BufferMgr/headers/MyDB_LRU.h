#ifndef MyDB_LRU_H
#define MyDB_LRU_H
#include <bits/stdc++.h>
#include "MyDB_Page.h"
using namespace std;
 
class LRUCache {
    // store keys of cache
private:
    std::list<MyDB_PagePtr> LRU;
    void removeNode();
    // size of cache, we don't need
    
    // store references of key in cache
    //unordered_map<MyDB_PagePtr, list<MyDB_Pageptr>::iterator> map;
    
public:
    // for now no parameter becuase the buffer manager holds the thing, all we need is a start point ptr
    LRUCache();
    ~LRUCache();
    void refer(MyDB_PagePtr);
    void findNode();
    void updateList();
    

};

#endif