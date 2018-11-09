#include "pecavermelha.h"
using namespace std;

PecaVermelha::PecaVermelha(float altura_, float largura_, float tempoProducao_): Peca(altura_,largura_,tempoProducao_,"vermelha"){}
PecaVermelha::~PecaVermelha(){}

float PecaVermelha::getTempoProducao()
{
	return 7*largura;
}

string PecaVermelha::print(){
	return "É uma peça vermelha.";
}