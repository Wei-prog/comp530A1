
#ifndef BUFFER_MGR_C
#define BUFFER_MGR_C

#include "MyDB_BufferManager.h"
#include "MyDB_LRU.h"
#include <string>
#include <list>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <map>
#include <utility>

using namespace std;

//constructor, we need pageSize, numPages in buffer, and temp location
//we want to create memory buffer, LRU list and an empty lookup table
MyDB_BufferManager:: MyDB_BufferManager(size_t page_size,size_t numPages,string tempFile){	

	this->page_size = page_size;
	this->numPages = numPages;
	this->tempFile = tempFile;
	// file.open(tempFile,fstream::out)
	for (size_t i =0 ; i<numPages;i++){
		this->memBuffer.push_back((void*)malloc(page_size));
	}
	//TODO: there is no need to initialize look up table or is there?
	this->lookupTable=std::map<pair<MyDB_TablePtr,long >, MyDB_Pageptr>();
	this->LRU = new LRUCache();

}


MyDB_BufferManager :: ~MyDB_BufferManager () {
	// Empty the lookupTable
	// for(auto page: this->lookupTable){

	// }

	//empty buffer
	for(auto buf:this->memBuffer){
		//write content to disk using LRU OR memBuffer TODO: ????
		buf.writeToDisk()
		free(buf);
	}
	for(auto kv :this->lookupTable){
		free(kv);
	}

	
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
	pair<MyDB_TablePtr,long> pageId = make_pair(whichTable,i);
	//if no such page found, create and push into table
	//see iterator find for iterating map
	map<pair<MyDB_TablePtr,long>,MyDB_Pageptr>::iterator it;
	it=this->lookupTable.find(pageId);
  if(it==this->lookupTable.end()){
		if (this->currLeftMem==0){
			this->evictPage();
		}
		MyDB_Pageptr naPage = make_shared<MyDB_Page> (whichTable,*this,i);
		(this->LRU)->updateList(naPage);
		return make_shared<MyDB_PageHandleBase> (naPage);
	}else{
		MyDB_Pageptr naPage = lookupTable[pageId]
		(this->LRU)->addPage(naPage); // TODO: Check the LRU function
		return make_shared<MyDB_PageHandleBase>(lookupTable[pageId]);
	}//if found return from table
	return nullptr;		
}

//anonymous
MyDB_PageHandle MyDB_BufferManager :: getPage () {
	//check available space, idea from other people
	if (this->currLeftMem==0){
		this->evictPage();
	}
	if (this->currLeftMem==0){
		//do nothing
		return nullptr;
	}
	//file index is ptr in file to find page
	pair<MyDB_TablePtr,long> whichPage = make_pair(nullptr,this->fileIndex);
	//to do::: see page constructor for anonymous page, the same. For aPage, key in lookuptable is nullptr, and fileindex
	//I really want to make the nullptr a file ptr
	//why using lookup table and they do not have id so not reusable.
	//for constructing page for aPage, whichtable is the filename, index is offset, and buffer manager is always this buffer manager
	MyDB_PagePtr aPage = make_shared<MyDB_Page>(*fileptrtolookfrom,*this,this->fileIndex)
	this->lookupTable[whichPage] = aPage;
	this->fileIndex +=1;
	return make_shared<MyDB_PageHandleBase> (aPage);		
}

//what is the difference? Keep an attribute isPin = true to avoid eviction,
//delete it from LRU and when unpinned, put back to LRU as most recently used
//similar to constructor overload get pinned/get page
MyDB_PageHandle MyDB_BufferManager :: getPinnedPage (MyDB_TablePtr whichTable, long i) {
	if(whichTable == nullptr){
		std:cout<<"null ptr whichTable, should be anaony"<<endl;
		exit(1);
	}
	pair<MyDB_TablePtr,long> whichPage = make_pair(whichTable,i);
	std::map<pair<>>::iterator it;
	it=lookupTable.find(pageId);
    if(it==lookupTable.end()){
		if (this->currLeftMem==0)
			this->evictPage();
		MyDB_Pageptr naPage = make_shared<MyDB_Page> (whichTable,*this,i);
		naPage.setPin(true);
		return make_shared<MyDB_PageHandleBase> (naPage);
	}
	else{
		MyDB_Pageptr naPage = lookupTable[pageId];
		naPage.setPin(true);
		return make_shared<MyDB_PageHandleBase>(lookupTable[pageId]);
	}//if found return from table		
	return nullptr;		
}

MyDB_PageHandle MyDB_BufferManager :: getPinnedPage () {
	if(this->currLeftMem==0)
		this->evictPage();
	pair<MyDB_Tableptr,long> whichPage = make_pair(nullptr,this->fileIndex);
	MyDB_Pageptr aPage = make_shared<MyDB_Page>(nullptr,*this,fileIndex);
	aPage->setPin(true);
	this->fileIndex +=1;
	pageTable[whichPage]=aPage;
	return make_shared<MyDB_PangeHandleBase>(aPage);

}

void MyDB_BufferManager :: unpin (MyDB_PageHandle unpinMe) {
	unpinMe->currPage->setPin(false);
}



#endif


