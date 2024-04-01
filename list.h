#ifndef LIST
#define LIST

#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class List
{
public:
    List();// constructor
    ~List(); // destructor


    bool IsEmpty()
    {
        return head == NULL;
    }
    Node<T> *InsertNode(T n, int index);
    int SearchNode(T n);
    int size;
private:
    Node<T> *head = NULL;
    Node<T> *tail = NULL;
    
};

#endif