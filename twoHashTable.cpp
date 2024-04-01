#include "twoHashTable.h"
#include "UPCEntry.h"
#include "list.h"
#include <fstream>   
#include <iostream>
using namespace std;

TwoHashTable::TwoHashTable(string filename, int size){ //inserts the file and size for the array
    this->size = size;
    arr = new List<UPCEntry>[size];
   
    lengths = new int[size];

    ifstream file;
    UPCEntry entry;
    string line;

    file.open(filename); getline(file,line);
    
    while(getline(file, line)){
        entry = UPCEntry(line);
        insert(entry);
    }
    for(int i = 0; i<size; i++){
        lengths[i] = arr[i].size;
    }
}

bool TwoHashTable::insert(UPCEntry &item){ //inserts the item into the list
    int hash1 = item.hash1(size);
    int hash2 = item.hash2(size);

    if(arr[hash1].size <= arr[hash2].size){
        arr[hash1].InsertNode(item, 0);
        return true;
    }
    if(arr[hash1].size > arr[hash2].size){
        arr[hash2].InsertNode(item, 0);
        return true;
    }
    return false;
}

Position TwoHashTable::search(UPCEntry &item){ 
    int hash1 = item.hash1(size);
    int hash2 = item.hash2(size);
    Position place;

    if(arr[hash1].SearchNode(item) != -1){//if searching the item in array at hash1 is not equal to -1, place the index in table as hash1 and set index in bin as the  
        place.indexInTable = hash1;
        place.indexInBin = arr[hash1].SearchNode(item);
        return place;
    }
    else if(arr[hash2].SearchNode(item) != -1){
        place.indexInTable = hash2;
        place.indexInBin = arr[hash2].SearchNode(item);
    }
    return place;
}

float TwoHashTable::getStdDev(){ //returns the standard deviation with lengths and size
    return stddev(lengths, size);
}