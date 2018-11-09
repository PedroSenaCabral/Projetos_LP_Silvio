#ifndef PECA_H
#define PECA_H
#include <string>
#include <iostream>
using namespace std;

class Peca
{
public:
	Peca(float altura_, float largura_, float tempoProducao_, string tipo);
	~Peca();
	
	float getAltura();
	float getLargura();
	virtual float getTempoProducao() = 0;
	virtual string print() = 0;
	friend ostream& operator<< (ostream &saida, Peca * peca);

	void setAltura(float altura_);
	void setLargura(float largura_);
	void setTempoProducao(float tempoProducao_);
	string getTipo();

protected:
	float altura, largura, tempoProducao;
	string tipo;
};

#endif



