#ifndef LISTA_H_
#define LISTA_H_

#include "No.h"

template <typename T>
class Lista {
private:
    int m_total_elementos;
    Node<T>* inicio;
    Node<T>* final;

	void unLinkNode(Node<T>* n);
	void linkNodeAfter(Node<T>* novo, Node<T>* nPrev);
	void linkNodeBefore(Node<T>* novo, Node<T>* nNext);

public:
	Lista();
	~Lista();

	T get(int posicao_);

	void inserirNoInicio(T elemento);
	void inserirNoFinal(T elemento);
	void inserirNaPosicao(T elemento, int posicao_);

    T removerDoInicio();
    T removerDoFinal();
	T removerDaPosicao(int posicao_);

    bool vazio();
    int tamanho();
};

template<typename T>
Lista<T>::Lista(){
	this->m_total_elementos = 0;
	this->inicio = nullptr;
	this->final = nullptr;
}

template<typename T>
Lista<T>::~Lista() {
	if(!this->vazio()){
		Node<T>* n = this->inicio;
		while(n->getNext() != nullptr){
			Node<T>* destruir = n;
			n = n->getNext();
			delete destruir;
		}
		delete n;
	}
}

template<typename T>
T Lista<T>::get(int posicao_){
    if (this->vazio())
    {
        // std::cerr << "Não há elementos na lista." << std::endl;
        exit(0);
    };
	if (posicao_ > this->m_total_elementos + 1)
    {
        // std::cerr << "Indice inválido! O ulitmo elemento sera retornado." << std::endl;
    };
    if (posicao_ < 1)
    {
		// std::cerr << "Indice inválido! O primeiro elemento sera retornado." << std::endl;
        posicao_ = 1;
    };
	Node<T> *aux = this->inicio;
	int counter = 1;
	while (aux->getNext() != nullptr && counter < posicao_)
	{
		aux = aux->getNext();
		counter++;
	};
	return aux->getValue();
}

template<typename T>
void Lista<T>::inserirNaPosicao(T elemento, int posicao_){
	
	if (posicao_ > this->m_total_elementos + 1)
    {
        // std::cerr << "Indice inválido! Elemento vai ser adicionado no final da sequencia." << std::endl;
    };

    if (posicao_ < 1)
    {
        posicao_ = 1;
    };

    Node<T>* novo = new Node<T>(elemento);
    
    if (this->vazio())
    {
        this->inicio = novo;
        this->final = novo;
    }
    else if(posicao_ > this->m_total_elementos){
		this->linkNodeAfter(novo, this->final);
    }
    else
    {
		Node<T> *aux = this->inicio;
        int counter = 1;
        while (aux->getNext() != nullptr && counter < posicao_)
        {
            aux = aux->getNext();
            counter++;
        };
		this->linkNodeBefore(novo, aux);
    };
    this->m_total_elementos++;
}

template<typename T>
void Lista<T>::inserirNoInicio(T elemento) {
	this->inserirNaPosicao(elemento, 1);
}

template<typename T>
void Lista<T>::inserirNoFinal(T elemento) {
	this->inserirNaPosicao(elemento, this->m_total_elementos+1);
}

template<typename T>
T Lista<T>::removerDaPosicao(int posicao_){
    if (this->vazio())
    {
        // std::cerr << "Não há elementos à remover." << std::endl;
        exit(0);
    };

    if (posicao_ > this->m_total_elementos || posicao_ < 1)
    {
        // std::cerr << "Indice fora do intervalo." << std::endl;
        exit(0);
    };

    Node<T>* toRemove = this->inicio;
    int counter = 1;
    while (toRemove->getNext() != nullptr && counter < posicao_)
    {
        toRemove = toRemove->getNext();
        counter++;
    };

	this->unLinkNode(toRemove);
    this->m_total_elementos--;

    T val = toRemove->getValue();
    delete toRemove;
    return val;
}

template<typename T>
T Lista<T>::removerDoInicio() {
	return this->removerDaPosicao(1);
}

template<typename T>
T Lista<T>::removerDoFinal() {
	return this->removerDaPosicao(this->m_total_elementos);
}

template<typename T>
bool Lista<T>::vazio() {
	return (m_total_elementos == 0);
}

template<typename T>
int Lista<T>::tamanho() {
	return m_total_elementos;
}

template<typename T>
void
Lista<T>::unLinkNode(Node<T>* n){
	if(n == nullptr){
		// cerr << "Nó inválido!" << endl;
		return;
	}
	Node<T>* nPrev = n->getPrevious();
	Node<T>* nNext = n->getNext();
	// atualize a linkagem dos nós anterior e posterior
	//   nPrev    n    nNext
	//     |             |
	//     --->-------<---
	if(nPrev != nullptr){
		nPrev->setNext(nNext);
	};
	if(nNext != nullptr){
		nNext->setPrevious(nPrev);
	};
	// remova os apontadores do no "n"
	n->setPrevious(nullptr);
	n->setNext(nullptr);
	// atualize os apontadores inicial e final
	if(n == this->inicio){
		this->inicio = nNext;
	};
	if(n == this->final){
		this->final = nPrev;
	};
}

template<typename T>
void
Lista<T>::linkNodeAfter(Node<T>* novo, Node<T>* nPrev){
	if(novo == nullptr || nPrev == nullptr){
		// cerr << "Nó inválido!" << endl;
		return;
	}
	Node<T>* nNext = nPrev->getNext();
	// posicionar o novo nó
	novo->setPrevious(nPrev);
	novo->setNext(nNext);
	// realizar a inserção do novo nó
	nPrev->setNext(novo);
	if(nNext != nullptr){ // se estivermos inserindo no final da lista o próximo nó será nullptr
		nNext->setPrevious(novo);
	};
	if(this->final == nPrev){ // se estivermos inserindo após o final, novo será o final
		this->final = novo;
	};
}

template<typename T>
void
Lista<T>::linkNodeBefore(Node<T>* novo, Node<T>* nNext){
	if(novo == nullptr || nNext == nullptr){
		// cerr << "Nó inválido!" << endl;
		return;
	}
	Node<T>* nPrev = nNext->getPrevious();
	// posicionar o novo nó
	novo->setPrevious(nPrev);
	novo->setNext(nNext);
	// realizar a inserção do novo nó
	if(nPrev != nullptr){ // se estivermos inserindo no inicio da lista o nó anterior será nullptr
		nPrev->setNext(novo);
	}
	nNext->setPrevious(novo);
	if(this->inicio == nNext){ // se estivermos inserindo antes do inicio, novo será o inicio
		this->inicio = novo;
	};
}

#endif /* defined(LISTA_H_) */
