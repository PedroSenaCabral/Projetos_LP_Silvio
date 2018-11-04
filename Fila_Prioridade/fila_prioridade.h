
#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include "fila.h"
#include "No.h"

template <typename T>
class Fila_Prioridade : public Fila<T>
{
public:
	Fila_Prioridade(int capacidade);
	~Fila_Prioridade();

	void enfileira(T& novo);
};

template <typename T>
Fila_Prioridade<T>::Fila_Prioridade(int capacidade):Fila<T>(capacidade){}

template <typename T>
Fila_Prioridade<T>::~Fila_Prioridade(){}

template <typename T>
void Fila_Prioridade<T>::enfileira(T& novo){

	if(this->cheia()){
		throw 1;
	}
	
	if(this->vazia()){
		this->m_elementos->inserirNoFinal(novo);
		return;
	}

	Node<T>* aux= this->m_elementos->getCalda()->getPrevious();
	int posicao= this->tamanho() + 1;

	while(aux != this->m_elementos->getCabeca() && novo > aux->getValue())
	{
		aux= aux->getPrevious();
		posicao--;
	}

	this->m_elementos->inserirNaPosicao(novo, posicao);

	return;

}

#endif