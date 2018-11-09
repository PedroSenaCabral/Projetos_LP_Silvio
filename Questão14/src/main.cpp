#include <iostream>
#include "fabrica.h"
#include "pecaamarela.h"
#include "pecaazul.h"
#include "pecavermelha.h"
using namespace std;

int main(int argc, char const *argv[])
{
	PecaAmarela * p1 = new PecaAmarela(5,5,10);	
	PecaAmarela * p2 = new PecaAmarela(5,7,30);

	PecaAzul * p3 = new PecaAzul(6,5,7);
	PecaAzul * p4 = new PecaAzul(9,9,60);
	PecaAzul * p7 = new PecaAzul(9,32,34);

	PecaVermelha * p5 = new PecaVermelha(6,5,7);
	PecaVermelha * p6 = new PecaVermelha(9,9,60);
	
	Fabrica * fabrica = new Fabrica();

	fabrica->addPecaProducao(p1);
	fabrica->addPecaProducao(p2);
	fabrica->addPecaProducao(p3);
	fabrica->addPecaProducao(p4);
	fabrica->addPecaProducao(p5);
	fabrica->addPecaProducao(p6);
	fabrica->addPecaProducao(p7);
	
	fabrica->printProducao();
	return 0;
}
