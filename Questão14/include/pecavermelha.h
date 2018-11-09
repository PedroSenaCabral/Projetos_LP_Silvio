#ifndef PECAVERMELHA_H
#define PECAVERMELHA_H
#include "peca.h"
#include <string>
using std::string;

class PecaVermelha: public Peca
{
public:
	PecaVermelha(float altura_, float largura_, float tempoProducao_);
	~PecaVermelha();

	float getTempoProducao();	
	string print();
};
#endif