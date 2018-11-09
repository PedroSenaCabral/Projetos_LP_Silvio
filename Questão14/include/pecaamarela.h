#ifndef PECAAMARELA_H
#define PECAAMARELA_H
#include "peca.h"
#include <string>
using std::string;

class PecaAmarela: public Peca
{
public:
	PecaAmarela(float altura_, float largura_, float tempoProducao_);
	~PecaAmarela();

	float getTempoProducao();
	string print();
};
#endif