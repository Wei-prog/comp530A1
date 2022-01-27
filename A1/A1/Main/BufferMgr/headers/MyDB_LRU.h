#ifndef MyDB_LRU
#define MyDB_LRY
#include <bits/stdc++.h>
#include "MyDB_Page.h"
using namespace std;
 
class LRUCache {
    // store keys of cache
    list<MyDB_PagePtr> LRU;

    // store references of key in cache
    unordered_map<MyDB_PagePtr, list<MyDB_Pageptr>::iterator> map;
    long size; // size of cache
 
public:
    LRUCache(long);
    void refer(MyDB_PagePtr);
};

#endif