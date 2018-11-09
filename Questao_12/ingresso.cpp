/**
 * @file ingresso.cpp
 * @author Igor Bruno (igoor.bruuno@gmail.com)
 * @brief Implementação das classes Ingresso e IngressoVIP, declaradas em ingresso.h
 * @version 0.1
 * @date 2018-11-08
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "ingresso.h"

using namespace std;

/**
 * @brief Construct a new Ingresso:: Ingresso object
 * 
 * @param valor_ Valor do ingresso
 * @param imposto_ Porcentagem de imposto do ingresso 
 */
Ingresso::Ingresso(float valor_, float imposto_):
    m_valor(valor_), m_imposto(imposto_/100){}

/**
 * @brief Destroy the Ingresso:: Ingresso object
 * 
 */
Ingresso::~Ingresso(){}

/**
 * @brief Retorna o valor total do ingresso.
 * 
 * @return float 
 */
float Ingresso::getTotal(){
    return m_valor;
}

/**
 * @brief Retorna o valor do imposto do ingresso.
 * 
 * @return float 
 */
float Ingresso::getImposto(){
    return m_valor * m_imposto;
}

ostream& operator<< (ostream &o, Ingresso &i) {
	o << "Valor do ingresso: R$" << i.getTotal() << endl << "Valor do imposto: R$" << i.getImposto() << endl;
	return o;
}

/**
 * @brief Construct a new Ingresso V I P:: Ingresso V I P object
 * 
 * @param adicional_ Valor adicional do ingresso VIP.
 * @param valor_ Valor do ingresso.
 * @param imposto_ Porcentagem de imposto do ingresso.
 */
IngressoVIP::IngressoVIP(float adicional_, float valor_, float imposto_):
    Ingresso(valor_ + adicional_, imposto_), m_adicional(adicional_){}

/**
 * @brief Destroy the Ingresso V I P:: Ingresso V I P object
 * 
 */
IngressoVIP::~IngressoVIP(){}

/**
 * @brief Retorna o valor adicional do ingresso VIP.
 * 
 * @return float 
 */
float IngressoVIP::getAdicional(){
    return m_adicional;
}

ostream& operator<< (ostream &o, IngressoVIP &i) {
	o << "Valor do ingresso VIP: R$" << i.getTotal() << endl << "Valor do imposto: R$" << i.getImposto() << endl;
	return o;
}