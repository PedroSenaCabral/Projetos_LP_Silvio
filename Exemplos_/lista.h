//Definição da classe Lista

#ifndef LISTA_H_
#define LISTA_H_

#include "No.h"

template <typename T>
class Lista {
private:
    int m_total_elementos;
    Node<T>* m_cabeca;
    Node<T>* m_calda;

public:
	Lista();
	~Lista();
	T removerDoInicio();
    void inserirNoFinal(T& elemento);
    int tamanho();

    /*
    Esse métodos foram implentados na própria fila
    T& vazio();
    T cheio();
   */
};

template <typename T>
Lista<T>::Lista():m_total_elementos(0){
	m_cabeca= new Node<T>();
	m_calda= new Node<T>();

	m_cabeca->setNext(m_calda);
	m_calda->setPrevious(m_cabeca);
}

template <typename T>
Lista<T>::~Lista(){}

template <typename T>
void Lista<T>::inserirNoFinal(T& elemento){

	Node<T>* novo= new Node<T>(elemento);

	novo->setNext(m_calda);
	novo->setPrevious(m_calda->getPrevious());

	novo->getNext()->setPrevious(novo);
	novo->getPrevious()->setNext(novo);

	m_total_elementos++; 

}

template <typename T>
T Lista<T>::removerDoInicio(){

	Node<T>* aux= m_cabeca->getNext(); 
	T elemento= aux->getValue();

	aux->getPrevious()->setNext(aux->getNext());
	aux->getNext()->setPrevious(m_cabeca);

	m_total_elementos--;
	delete aux;

	return elemento;

}

template <typename T>
int Lista<T>::tamanho(){
	return m_total_elementos;
}

#endif 
