#include "peca.h"

Peca::Peca(float altura_, float largura_, float tempoProducao_, string tipo_): altura(altura_), largura(largura_), tempoProducao(tempoProducao_), tipo(tipo_){}
Peca::~Peca(){}

float Peca::getTempoProducao()
{
	return tempoProducao;
}
float Peca::getAltura()
{
	return altura;
}

float Peca::getLargura()
{
	return largura;
}

void Peca::setAltura(float altura_)
{
	altura = altura_;
}

void Peca::setLargura(float largura_)
{
	largura = largura_;
}
void Peca::setTempoProducao(float tempoProducao_)
{
	tempoProducao = tempoProducao_;
}

string Peca::getTipo()
{
	return tipo;
}

ostream& operator<< (ostream &saida, Peca * peca)
{
	saida << peca->print(); 
	return saida;
}