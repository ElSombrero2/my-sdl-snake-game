#ifndef __COLLECTION_H__
#define __COLLECTION_H__

template <typename T>
class Node{
public:
    T value;
    Node<T>* next;
};

template <typename T>
class Queue{
private:
    Node<T>* t;
    Node<T>* q;
    int size;
    Node<T>* init(T);
public:
    Queue();
    int count();
    void push(T);
    T pop();
    T* toArray();
    T peekFirst();
    T peekLast();
    void foreach(void(*f)(T obj));
    Node<T>* getFirst();
};

#include "collection.hpp"
#endif