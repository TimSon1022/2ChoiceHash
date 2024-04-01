#include "UPCEntry.h"
#include <iostream>
using namespace std;
int number = 0;
UPCEntry::UPCEntry(){} //default constructor

UPCEntry::UPCEntry(string entry){ //cuts off string at comma
    string delimiter = ",";
    this->upc = stoll(entry.substr(0,entry.find(delimiter)));
    entry.erase(0,entry.find(delimiter));
    entry.erase(0,1);
    this->desc = entry;
}

bool UPCEntry::operator!=(const UPCEntry other){
        if (this->desc != other.desc || this->upc != other.upc){
            return true;
        }       
        return false;       
    }
