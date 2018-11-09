#include "funcionario.h"
#include <string>

using namespace std;
Funcionario::Funcionario(string nome_,int idade_,float altura_, string matricula_, float salario_):
	Pessoa(nome_,idade_,altura_),m_matricula(matricula_),m_salario(salario_){

}

Funcionario::~Funcionario(){
}


string Funcionario::getMatricula(){
	return m_matricula;
}
void Funcionario::setMatricula(std::string matricula_){
	m_matricula = matricula_;
}
float Funcionario::getSalario(){
	return m_salario;
}
void Funcionario::setSalario(float salario_){
	m_salario = salario_;
}

void Funcionario::print(){

}

ostream& operator<< (ostream &o, Funcionario *f) {
	 f->print();
return o;
}