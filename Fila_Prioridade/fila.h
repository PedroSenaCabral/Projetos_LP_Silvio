//CRIAR UMA TAD FILA E DEPOIS TRANSFORMAR NUMA TAD FILA DE PRIORIDADE
#ifndef FILA_H
#define FILA_H

#include <iostream>

#include "lista.h"

template <typename T>
class Fila{
	protected:
		Lista<T> * m_elementos;
		int m_capacidade;

	public:
		Fila(int capacidade_);
		~Fila();

		void enfileira(T& novo_);
		T desenfileira();
		bool vazia();
		bool cheia();
		int tamanho();

};

template<typename T>
Fila<T>::Fila(int capacidade_):
	m_elementos(new Lista<T>()),
	m_capacidade(capacidade_){}

template<typename T>
Fila<T>::~Fila(){}

template<typename T>
void Fila<T>::enfileira(T& novo_){
	if(cheia()){
		throw 1;
	}
	this->m_elementos->inserirNoFinal(novo_);
}

template<typename T>
T Fila<T>::desenfileira(){
	
	return this->m_elementos->removerDoInicio();
}

template<typename T>
bool Fila<T>::vazia(){
	return (this->m_elementos->vazia());
}

template<typename T>
bool Fila<T>::cheia(){
	return (this->m_elementos->getTotalElementos() == m_capacidade);
}

template<typename T>
int Fila<T>::tamanho(){
	return this->m_elementos->getTotalElementos();
}

#endif