#include "assistenteAdministrativo.h"
#include <string>
#include <iostream>
using namespace std;
AssistenteAdministrativo::AssistenteAdministrativo(string nome_,int idade_,float altura_, string matricula_, float salario_,string turno_,float participacao_):
	Funcionario(nome_,idade_,altura_,matricula_,salario_),m_turno(turno_),m_participacao(participacao_){

}

AssistenteAdministrativo::~AssistenteAdministrativo(){
}

string AssistenteAdministrativo::getTurno(){
	return m_turno;
}
void AssistenteAdministrativo::setTurno(string turno_){
	m_turno = turno_;
}

float AssistenteAdministrativo::getParticipacao(){
	return m_participacao;
}
void AssistenteAdministrativo::setParticipacao(float participacao_){
	m_participacao = participacao_;
}

void AssistenteAdministrativo::print() {
	cout<< "Nome:" << getNome() << "|" << "Idade: "<<getIdade() << "|" <<"Altura: " <<getAltura()<<endl;
	cout<< "Matricula: "<<  getMatricula() <<"|" <<"Salario: " << getSalario() <<endl;
	cout<< "Turno: " <<getTurno() <<"|"<<"Participacao: "<< getParticipacao()<<endl;
}