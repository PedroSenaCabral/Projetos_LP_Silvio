#include "pecaamarela.h"

using namespace std;

PecaAmarela::PecaAmarela(float altura_, float largura_, float tempoProducao_): Peca(altura_,largura_,tempoProducao_, "amarela"){}
PecaAmarela::~PecaAmarela(){}

float PecaAmarela::getTempoProducao()
{
	return altura*largura;
}

string PecaAmarela::print()
{
	return "É uma peça amarela.";
}