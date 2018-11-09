#ifndef FABRICA_H
#define FABRICA_H

#include <ostream>
#include "pecaamarela.h"
#include "pecaazul.h"
#include "pecavermelha.h"
using namespace std;
#define MAX_PECAS 100

class Fabrica
{
public:
	Fabrica();
	~Fabrica();
	
	void addPecaProducao(Peca * p);
	float calcTempoProducao();
	float getTempoTotalProducao();
	int getTotalPecasProduzidas();
	void printProducao();

private:
	int totalPecasProduzidas;
	float tempoTotalProducao;
	Peca * pecasProduzidas[MAX_PECAS];

};
#endif

