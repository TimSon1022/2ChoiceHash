#include "list.h"
#include "UPCEntry.h"
using namespace std;


template <class T>
List<T>::List(){  //constructor  
    head = NULL;
    tail = NULL;
    size = 0; 
}

template <class T>
List<T>::~List()//destructor
{
    Node<T> *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        // destroy the current node
        delete curr;
        curr = next;
    }
}

template <class T>
Node<T> *List<T>::InsertNode(T n, int index)//inserts new node at an index
{
    if (index < 0){
        return NULL;
    }

    int prevNum = 0;
    Node<T> *prev = this->head;
    while (prev != NULL && index - 1 > prevNum)
    {
        prev = prev->next;
        prevNum++;
    }
    if (index > 0 && prev == NULL)
        return NULL;

    Node<T> *New = new Node<T>;
    New->data = n;
    if (index == 0)
    {
        New->next = this->head;
        this->head = New;
    }
    else
    {
        New->next = prev->next;
        prev->next = New;
    }
    size++;
    if (index == size - 1)
        this->tail = New;
    return New;
}

template <class T>
int List<T>::SearchNode(T n)// tries to find the node and get the index of where it's at
{
    Node<T> *curr = this->head;
    int currNum = 0;
    while (curr && curr->data != n)
    {
        curr = curr->next;
        currNum++;
    }
    if (curr)
        return currNum; //if can't find the index return -1
    return -1;
}





