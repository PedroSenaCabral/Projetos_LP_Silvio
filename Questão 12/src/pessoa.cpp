#include <string>
#include <iostream>
#include <ostream>
#include "pessoa.h"
using namespace std;

Pessoa::Pessoa(string nome_,int idade_,float altura_):
	m_nome(nome_),m_idade(idade_),m_altura(altura_){
}
Pessoa::~Pessoa(){
}

void Pessoa::setNome(string nome_){
	m_nome = nome_;
}
string Pessoa::getNome(){
	return m_nome;
}

void Pessoa::setIdade(int idade_){
	m_idade = idade_;
}
int Pessoa::getIdade(){
	return m_idade;
}

void Pessoa::setAltura(float altura_){
	m_altura = altura_;
}
float Pessoa::getAltura(){
	return m_altura;
}

ostream& operator<< (ostream &o, Pessoa *p) {
o <<"Nome:"<< p->m_nome << " |Idade:" << p->m_idade << " |Altura:" << p->m_altura<<endl;
return o;
}