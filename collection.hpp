#include <iostream>

template <typename T>
Queue<T>::Queue(){
    this->size=0;
    this->t=this->q=NULL;
}

template <typename T>
Node<T>* Queue<T>::init(T value)
{
    Node<T>* tmp=new Node<T>;
    tmp->value=value;
    tmp->next=NULL;
    this->size++;
    return tmp;
}

template <typename T>
int Queue<T>::count(){return this->size;}

template <typename T>
void Queue<T>::push(T value)
{
    if(this->t==NULL)this->t=this->q=init(value);
    else{
        Node<T>* tmp=new Node<T>;
        tmp->value=value;
        tmp->next=NULL;
        this->q->next=tmp;
        this->q=tmp;
        this->size++;
    }
}

template <typename T>
T Queue<T>::pop()
{
    Node<T>* tmp=this->t;
    if(tmp==NULL)exit(-1);
    T val=tmp->value;
    this->t=tmp->next;
    if(this->t==NULL)this->q=NULL;
    delete tmp;
    this->size--;
    return val;
}

template <typename T>
T* Queue<T>::toArray()
{
    T* array=new T[this->size];
    Node<T>* tmp=this->t;
    int i=0;
    while(tmp!=NULL){
        array[i++]=tmp->value;
        tmp=tmp->next;
    }
    return array;
}

template <typename T>
void Queue<T>::foreach(void(*f)(T obj))
{
    Node<T>* tmp=this->t;
    while(tmp!=NULL){
        f(tmp->value);
        tmp=tmp->next;
    }
}

template <typename T>
Node<T>* Queue<T>::getFirst(){return this->t;}



template <typename T>
T Queue<T>::peekFirst(){return this->t->value;}

template <typename T>
T Queue<T>::peekLast(){return this->q->value;}