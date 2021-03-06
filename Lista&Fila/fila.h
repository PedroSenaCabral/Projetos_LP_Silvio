//CRIAR UMA TAD FILA E DEPOIS TRANSFORMAR NUMA TAD FILA DE PRIORIDADE
#ifndef FILA_H
#define FILA_H

#include <iostream>
#include <memory>
#include "lista.h"

using namespace std;

template <typename T>
class Fila{
	private:
		Lista<T> * m_elementos;
		//Não é necessário um atributo para o tamanho da Fila, pois já a Lista já possui esse elemento.
		int m_capacidade;

	public:
		
		Fila(int capacidade_);
		~Fila();

		void enfileira(T elemento_);
		T desenfileira();
		bool vazio();
		bool cheio();
		int tamanho();

};

template<typename T>
Fila<T>::Fila(int capacidade_){
	m_elementos = new Lista<T>();
	m_capacidade = capacidade_;
}

template<typename T>
Fila<T>::~Fila(){
	delete m_elementos;	
}

template<typename T>
void Fila<T>::enfileira(T elemento_){
	if(tamanho() >= m_capacidade) {
		cout << endl << "\nTentando add "<< elemento_ <<" na fila." << endl;
		cout << "A fila chegou no seu limite." << endl;
	} else {
		this->m_elementos->inserirNoFinal(elemento_);
		cout << elemento_ << " foi adicionado com sucesso." << endl;
	}
}

template<typename T>
T Fila<T>::desenfileira(){
	if(vazio()){
		cerr << "ERRO! Fila esta vazia. Nao desenfileira" << endl;
		exit(0);
	}
	cout << "Chamando o proximo da fila: " << endl;
	return this->m_elementos->removerDoInicio();	
}

template<typename T>
bool Fila<T>::vazio(){
	return this->m_elementos->vazio();
}

template<typename T>
bool Fila<T>::cheio(){
	return (this->m_elementos->tamanho() == m_capacidade);
}

template<typename T>
int Fila<T>::tamanho(){
	return this->m_elementos->tamanho();
}

#endif