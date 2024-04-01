#ifndef TWO_HASH_TABLE
#define TWO_HASH_TABLE
#include "position.h"
#include "UPCEntry.h"
#include <cmath>
#include "list.h"
using namespace std;

class TwoHashTable
{
public:
    int size = 0; 
    List<UPCEntry> *arr; 
    int *lengths; 

    TwoHashTable(string filename, int tableSize); 
    bool insert(UPCEntry &item);     
    Position search(UPCEntry &item); 
    float getStdDev(); 

private:
    float stddev(int *binLengths, int tableSize)
    {
        float sum = 0;
        for (int i = 0; i < tableSize; i++)
            sum += binLengths[i];

        float avarage = sum / tableSize;

        float dev_sum = 0;
        for (int i = 0; i < tableSize; i++)
        {
            dev_sum = dev_sum + (binLengths[i] - avarage) * (binLengths[i] - avarage);
        }

        float variance = dev_sum / tableSize;
        return sqrt(variance);
    }
};
#endif