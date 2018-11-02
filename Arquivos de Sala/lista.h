#ifndef LISTA_H_
#define LISTA_H_

#include "No.h"

template <typename T>
class Lista {
private:
    int m_total_elementos;
	T* m_inicio;
	T* m_final;
public:
	Lista();
	~Lista();
	void inserirDoInicio(T& no);
	void inserirNoFinal(T& no);
    T& removerDoInicio();
    T& removerNofinal();
    bool vazio();
    int  tamanho();
};

template<typename T>
Lista<T>::Lista():m_total_elementos(0){
	m_inicio(NULL);
	m_final(NULL);
}

template<typename T>
Lista<T>::~Lista(){}

template<typename T>
void Lista<T>::inserirDoInicio(T& no) {

	if(m_total_elementos == 0) {
		m_inicio = &no;
		m_final = &no;	
	} else if (m_total_elementos == 1){
		m_inicio = &no;
		m_inicio->setNext(m_final);
		m_final->setPrevious(m_inicio);

	} else {
		no.setNext(m_inicio);
		m_inicio->setPrevious(&no);
		m_inicio = &no;
	}
	m_total_elementos++;	
}

template<typename T>
void Lista<T>::inserirNoFinal(T& no) {

	if(m_total_elementos == 0) {
		m_inicio = &no;
		m_final = &no;	
	} else if (m_total_elementos == 1){
		m_final = &no;
		m_inicio->setNext(m_final);
		m_final->setPrevious(m_inicio);
	} else {
		m_final->setNext(&no);
		no.setPrevious(m_final);
		m_final = &no;
	}
	m_total_elementos++;	
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

	T* aux = final;
	final = final->getPrevious();
	m_total_elementos--;	
	return (*aux);
	return (*aux);
}

template<typename T>
int Lista<T>::tamanho() {
	return m_total_elementos;
}

#endif /* defined(__LinkedList__LinkedList__) */