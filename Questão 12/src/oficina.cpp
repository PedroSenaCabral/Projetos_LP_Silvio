#include "oficina.h"
#include <iostream>
using namespace std;
Oficina::Oficina(Gerente *gerente_):
	m_gerente(gerente_),m_numero_funcionarios(0){

}

Oficina::~Oficina(){
}

void Oficina::addFuncionario(Funcionario *funcionario_){
	if(m_numero_funcionarios<MAX_FUNCIONARIOS){
		m_funcionarios[m_numero_funcionarios++]= funcionario_;
	}else{
		cout<<"Máximo de funcionários atingido"<<endl;
	}
}

ostream& operator<< (ostream &o, Oficina *of){
	 o<<"Dados do Gerente da Oficina: "<<endl;
	 o<<of->m_gerente;
	 o<<"Dados dos Funcionários da empresa: "<<endl;
	 for (int i = 0; i < of->m_numero_funcionarios; i++){
	 	o<<"Dados do Funcionário "<<i<<": "<<endl;
	 	o<<of->m_funcionarios[i]<<endl;
	 }
return o;
}