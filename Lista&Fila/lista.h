#ifndef LISTA_H_
#define LISTA_H_

#include "No.h"

template <typename T>
class Lista {
private:
    int m_total_elementos;
    T* inicio;
    T* final;
    T* posicao;

public:
	Lista();
	~Lista();
	void inserirNoInicio(T& no);
	void inserirNaPosicao(T& no, posicao_);
	void inserirNoFinal(T& no);
    T& removerDoInicio();
    T& removerDoFinal();
    bool vazio();
    int tamanho();

};

template<typename T>
Lista<T>::Lista(){
	this->m_total_elementos = 0;
	inicio = NULL;
	final = NULL;
	posicao = NULL;
}

template<typename T>
Lista<T>::~Lista() {

}

template<typename T>
void Lista<T>::inserirNoInicio(T& no) {

	if(m_total_elementos == 0) {

		inicio = &no;
		final = &no;
	
	} else if (m_total_elementos == 1){

		inicio = &no;
		inicio->setNext(final);
		final->setPrevious(inicio);

	} else {

		no.setNext(inicio);
		inicio->setPrevious(&no);
		inicio = &no;

	}

	m_total_elementos++;	

}

template<typename T>
void Lista<T>::inserirNaPosicao(T& no, posicao_){
	
	if(m_total_elementos == 0) {

		inicio = &no;
		posicao = &no;
		final = &no;

	} else if (m_total_elementos == 1){

		posicao = &no;
		inicio->setNext(final);
		final->setPrevious(inicio);
	
	} else if (m_total_elementos > 1){

		//posicao
		inicio = &no;
		inicio->setNext(final);
		final->setPrevious(inicio);
	}

	m_total_elementos++;	

}
//EXEMPLO//
    // if (i < 0)
    //     return;
    // if (i == 0)
    // {
    //     inserirPrimeiro(valor);
    //     return;
    // }
    // if (tamanho() >= i)
    // {
    //     No *no = primeiro, *aux, *novo;
    //     novo = (No*) malloc (sizeof(No));
    //     novo->info = valor;
    //     int cont = 0;//para contagem da posição a partir de 0
    //     while (cont < i-1)//i-1 para parar uma posição antes de i, para fazer a inserção na posição certa
    //     {
    //         no = no->proximo;
    //         cont++;
    //     }
    //     aux = no->proximo;
    //     no->proximo = novo;
    //     novo->proximo = aux;
    // }

template<typename T>
void Lista<T>::inserirNoFinal(T& no) {

	if(m_total_elementos == 0) {

		inicio = &no;
		final = &no;
	
	} else if (m_total_elementos == 1){

		final = &no;
		inicio->setNext(final);
		final->setPrevious(inicio);

	} else {

		final->setNext(&no);
		no.setPrevious(final);
		final = &no;

	}

	m_total_elementos++;	

}

template<typename T>
int Lista<T>::tamanho() {
	return m_total_elementos;
}


template<typename T>
T& Lista<T>::removerDoInicio() {

	T* aux  = inicio;

	inicio = inicio->getNext();
	m_total_elementos--;	
	return (*aux);
}



template<typename T>
T& Lista<T>::removerDoFinal() {

	T* aux  = final;

	final = final->getPrevious();
	m_total_elementos--;	
	return (*aux);

	return (*aux);
}

template<typename T>
bool Lista<T>::vazio() {
	return m_total_elementos == 0;
}

#endif /* defined(__LinkedList__LinkedList__) */
