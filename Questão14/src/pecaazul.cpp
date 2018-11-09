#include "pecaazul.h"
using namespace std;

PecaAzul::PecaAzul(float altura_, float largura_, float tempoProducao_): Peca(altura_,largura_,tempoProducao_,"azul"){}
PecaAzul::~PecaAzul(){}

float PecaAzul::getTempoProducao()
{
	return altura*15;
}

string PecaAzul::print()
{
	return "É uma peça azul.";
}