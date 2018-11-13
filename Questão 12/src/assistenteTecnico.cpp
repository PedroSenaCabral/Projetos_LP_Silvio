#include "assistenteTecnico.h"
#include <string>
#include <iostream>
using namespace std;
AssistenteTecnico::AssistenteTecnico(string nome_,int idade_,float altura_, string matricula_, float salario_,float bonus_salarial_,Funcionario *supervisor_):
	Funcionario(nome_,idade_,altura_,matricula_,salario_+bonus_salarial_),m_bonus_salarial(bonus_salarial_),m_supervisor(supervisor_){

}

AssistenteTecnico::~AssistenteTecnico(){
}

float AssistenteTecnico::getBonusSalarial(){
	return m_bonus_salarial;
}
void AssistenteTecnico::setBonusSalarial(float bonus_salarial_){
	m_bonus_salarial = bonus_salarial_;
}

Funcionario* AssistenteTecnico::getSupervisor(){
	return m_supervisor;
}
void AssistenteTecnico::setSupervisor(Funcionario *supervisor_){
	m_supervisor = supervisor_;
}

void AssistenteTecnico::print() {
	cout<< "Nome:" << getNome() << "|" << "Idade: "<<getIdade() << "|" <<"Altura: " <<getAltura()<<endl;
	cout<< "Matricula: "<<  getMatricula() <<"|" <<"Salario: " << getSalario() <<endl;
	cout<< "Bonus Salarial: " <<getBonusSalarial() <<endl;
	cout<<"Supervisor: "<< getSupervisor()->getNome()<<endl;
}