#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include "pessoa.h"
#include <string>
#include <ostream>
using namespace std;
class Funcionario: public Pessoa{
protected:
	std::string m_matricula;
	float m_salario;

public:
	Funcionario(std::string nome_,int idade_,float altura_, std::string matricula_, float salario_);
	~Funcionario();
	std::string getMatricula();
	void setMatricula(std::string matricula_);
	float getSalario();
	void setSalario(float salario_);
	virtual void print()=0;
	friend ostream& operator<<(ostream &o, Funcionario * f);
};
#endif