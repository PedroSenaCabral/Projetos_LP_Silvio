#ifndef Pessoa_H
#define Pessoa_H
#include <string>
#include <ostream>
using namespace std;
class Pessoa{
protected:
	string m_nome;
	int m_idade;
	float m_altura;
public:
	Pessoa(string nome_,int idade_,float altura_);
	~Pessoa();

	void setNome(string nome_);
	string getNome();

	void setIdade(int idade_);
	int getIdade();

	void setAltura(float altura_);
	float getAltura();

	friend ostream& operator<< (ostream &o, Pessoa * p);
	
};
#endif