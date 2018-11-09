#include "gerente.h"
#include <string>

using namespace std;
Gerente::Gerente(string nome_,int idade_,float altura_, string matricula_, float salario_):
	Pessoa(nome_,idade_,altura_),m_matricula(matricula_),m_salario(salario_){

}

Gerente::~Gerente(){
}


string Gerente::getMatricula(){
	return m_matricula;
}
void Gerente::setMatricula(std::string matricula_){
	m_matricula = matricula_;
}
float Gerente::getSalario(){
	return m_salario;
}
void Gerente::setSalario(float salario_){
	m_salario = salario_;
}

void Gerente::print() {

	cout<< "Nome:" << getNome() << "|" << "Idade"<<getIdade() << "|" <<"Altura: " <<getAltura()<<endl;
	cout<< "Matricula"<<  getMatricula() <<"|" <<"Salario: " << getSalario() <<endl;

}