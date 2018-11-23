#ifndef GERENTE_H
#define GERENTE_H
#include "pessoa.h"
#include <string>
class Gerente: public Pessoa{
private:
	std::string m_matricula;
	float m_salario;

public:
	Gerente(std::string nome_,int idade_,float altura_, std::string matricula_, float salario_);
	~Gerente();
	std::string getMatricula();
	void setMatricula(std::string matricula_);
	float getSalario();
	void setSalario(float salario_);
	void print();
};
#endif