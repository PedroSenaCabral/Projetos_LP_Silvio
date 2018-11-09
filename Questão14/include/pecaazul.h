#ifndef PECAAZUL_H
#define PECAAZUL_H
#include "peca.h"
#include <string>
using std::string;

class PecaAzul: public Peca
{
public:
	PecaAzul(float altura_, float largura_, float tempoProducao_);
	~PecaAzul();

	float getTempoProducao();
	string print();
};
#endif