#ifndef NODE_H_
#define NODE_H_

#include <iostream>

template <typename T>
class Node{
private:
    T value;
    Node* next;
    Node* prev;
    
public:
    Node();
    Node( T );
    Node( T, Node*, Node* );
    T getValue();
    void setValue(T val);
    Node* getNext();
    void setNext(Node*);
	Node* getPrevious();
	void setPrevious(Node*);
};

template<typename T>
Node<T>::Node():
next(nullptr), prev(nullptr) {}

template<typename T>
Node<T>::Node(T val):
value(val), next(nullptr), prev(nullptr) {}

template<typename T>
Node<T>::Node(T val, Node* n, Node* p):
value(val), next(n), prev(p) {}

template<typename T>
T
Node<T>::getValue(){
    return this->value;
}

template<typename T>
Node<T>*
Node<T>::getNext(){
    return this->next;
}

template<typename T>
void
Node<T>::setNext(Node<T>* n){
    this->next = n;
}

template<typename T>
Node<T>*
Node<T>::getPrevious(){
	return this->prev;
}

template<typename T>
void
Node<T>::setPrevious(Node<T>* p){
	this->prev = p;
}


#endif /* defined(__LinkedList__Node__) */
