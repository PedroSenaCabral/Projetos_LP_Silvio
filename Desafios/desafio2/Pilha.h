//CRIAR UMA TAD Pilha E DEPOIS TRANSFORMAR NUMA TAD Pilha DE PRIORIDADE
#ifndef Pilha_H
#define Pilha_H

#include <iostream>
#include <memory>
#include "lista.h"

using namespace std;

template <typename T>
class Pilha{
	private:
		Lista<T> * m_elementos;
		//Não é necessário um atributo para o tamanho da Pilha, pois já a Lista já possui esse elemento.
		int m_capacidade;

	public:
		
		Pilha(int capacidade_);
		~Pilha();

		void empilhar(T elemento_);
		T desempilhar();
		bool vazio();
		bool cheio();
		int tamanho();

};

template<typename T>
Pilha<T>::Pilha(int capacidade_){
	m_elementos = new Lista<T>();
	m_capacidade = capacidade_;
}

template<typename T>
Pilha<T>::~Pilha(){
	delete m_elementos;	
}

template<typename T>
void Pilha<T>::empilhar(T elemento_){
	if(tamanho() >= m_capacidade) {
		cout << endl << "\nTentando add "<< elemento_ <<" na Pilha." << endl;
		cout << "A Pilha chegou no seu limite." << endl;
	} else {
		this->m_elementos->inserirNoFinal(elemento_);
		cout << elemento_ << " foi adicionado com sucesso." << endl;
	}
}

template<typename T>
T Pilha<T>::desempilhar(){
	if(vazio()){
		cerr << "ERRO! Pilha esta vazia. Nao desempilhar" << endl;
		exit(0);
	}
	cout << "desempilhando o proximo da Pilha: " << endl;
	return this->m_elementos->removerDoFinal();	
}

template<typename T>
bool Pilha<T>::vazio(){
	return this->m_elementos->vazio();
}

template<typename T>
bool Pilha<T>::cheio(){
	return (this->m_elementos->tamanho() == m_capacidade);
}

template<typename T>
int Pilha<T>::tamanho(){
	return this->m_elementos->tamanho();
}

#endif