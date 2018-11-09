//Definição da classe Lista

#ifndef LISTA_H_
#define LISTA_H_

#include <iostream>
#include <string>
using namespace std;
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

	Node<T>* getCabeca();
	Node<T>* getCalda();

	//Insere um elemento no início da lista
	void inserirNoInicio(T& elemento);
	//Insere um elemento no final da lista
    void inserirNoFinal(T& elemento);
    //Insere um elemento na lista na posição passada por parâmetro.
    void inserirNaPosicao(T& elemento, int posicao);

    //Remove um elemento no início da lista
	T removerDoInicio();
	//Remove um elemento no final da lista
	T removerDoFinal();
	//Remove um elemento na lista na posição passada por parâmetro.
	T removerDaPosicao(int posicao);

	//Retorna a quantidade de elementos que tem na lista
    int getTotalElementos();
    //Retorna o elemento da posição que foi passada por parâmetro
    T getElemento(int posicao);
    //Verifica se a fila está vazia e retorna verdadeiro ou falso.
    bool vazia();
    
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
Node<T>* Lista<T>::getCabeca(){
	return m_cabeca;
}
template <typename T>
Node<T>* Lista<T>::getCalda(){
	return m_calda;
}

template <typename T>
void Lista<T>::inserirNoInicio(T& elemento){

	Node<T>* novo= new Node<T>(elemento);

	novo->setNext(m_cabeca->getNext());
	novo->setPrevious(m_cabeca);

	novo->getNext()->setPrevious(novo);
	novo->getPrevious()->setNext(novo);

	m_total_elementos++; 

}

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
void Lista<T>::inserirNaPosicao(T& elemento, int posicao){

	if(posicao < 1 || posicao > (m_total_elementos + 1)){
		cerr<< "O Valor do indice da posicao deve estar entre [1,"<<m_total_elementos + 1<<"]."<<endl;
		return;
	}

	if(posicao == 1){
		return inserirNoInicio(elemento);
	}
	else if(posicao == m_total_elementos+1){
		return inserirNoFinal(elemento);
	}
	else{

		Node<T>* aux= m_cabeca->getNext();
		int cont=1;
		while(cont != posicao-1)
		{
			aux= aux->getNext();
			cont++;
		}

		Node<T>* novo= new Node<T>(elemento);

		novo->setNext(aux->getNext());
		novo->setPrevious(aux);
		novo->getNext()->setPrevious(novo);
		novo->getPrevious()->setNext(novo);

		m_total_elementos++;
	}

}

template <typename T>
T Lista<T>::removerDoInicio(){

	if(vazia()){
		throw 1; //Nao existem elementos na lista
	}

		Node<T>* aux= m_cabeca->getNext(); 
		T elemento= aux->getValue();

		aux->getPrevious()->setNext(aux->getNext());
		aux->getNext()->setPrevious(m_cabeca);

		m_total_elementos--;
		delete aux;

		return elemento;
		
}

template <typename T>
T Lista<T>::removerDoFinal(){

	if(vazia()){
		throw 1; //"Nao existem elementos!";
	}

	Node<T>* aux= m_calda->getPrevious(); 
	T elemento= aux->getValue();

	aux->getPrevious()->setNext(aux->getNext());
	aux->getNext()->setPrevious(aux->getPrevious());

	m_total_elementos--;
	delete aux;

	return elemento;

}

//Falta corrigir o retorno para quando a posição passada for maior que a quantidade de elementos
template <typename T>
T Lista<T>::removerDaPosicao(int posicao){

	if(vazia()){
		throw 1; //"Nao existem elementos!";
	}
	if(posicao < 1 || posicao > m_total_elementos){
		throw 2; //"Posicao inexistente";
	}

	if(posicao == 1){
		return removerDoInicio();
	}
	else if(posicao == m_total_elementos){
		return removerDoFinal();
	}
	else{
		Node<T>* remover= m_cabeca->getNext();
		int cont=1;
		while(cont != posicao)
		{
			remover= remover->getNext();
			cont++;
		}

		T elemento= remover->getValue();

		remover->getPrevious()->setNext(remover->getNext());
		remover->getNext()->setPrevious(remover->getPrevious());
		
		m_total_elementos--;
		delete remover;

		return elemento;
	}
}

template <typename T>
int Lista<T>::getTotalElementos(){
	return m_total_elementos;
}

template <typename T>
T Lista<T>::getElemento(int posicao){

	if(vazia()){
		throw 1; //"Nao existem elementos!";
	}
	 if( posicao < 1 || posicao > this->getQuantity())
    {
        throw 2; //"Posicao inexistente";
    }
    
    int counter = 1;
    
    string result;
    for(Node<string>* n = this->head->getNext(); n != this->tail; n = n->getNext())
    {
        if( posicao == counter )
        {
            result = n->getValue();
            break;
        }
        counter++;
    }
    
    return result;

}

template <typename T>
bool Lista<T>::vazia(){
	return m_total_elementos == 0;
}

#endif 
