#include "fabrica.h"
#include <iostream>
using namespace std;
Fabrica::Fabrica(): totalPecasProduzidas(0), tempoTotalProducao(0) {}

Fabrica::~Fabrica(){}

void Fabrica::addPecaProducao(Peca * p)
{
	if (totalPecasProduzidas<MAX_PECAS)
	{
		pecasProduzidas[totalPecasProduzidas++] = p;
		cout << "Uma peca " << p->getTipo() << " foi adicionada a lista de produção." << endl;
		return;
	}
	cerr << "Produção está com capacidade máxima." << endl;
}

int Fabrica::getTotalPecasProduzidas()
{
	return totalPecasProduzidas;
}

float Fabrica::calcTempoProducao()
{
	tempoTotalProducao = 0;
	for (int i = 0; i < totalPecasProduzidas; ++i){
		tempoTotalProducao += pecasProduzidas[i]->getTempoProducao(); 
	}
	return tempoTotalProducao;
}
	
float Fabrica::getTempoTotalProducao()
{
	return calcTempoProducao();
}
	
/*void Fabrica::printProducao()
{
	int amarelas = 0,vermelhas = 0 ,azuis = 0;
	
	cout << "Total de Peças produzidas: " << totalPecasProduzidas << endl;
	
	for (int i = 0; i < totalPecasProduzidas; ++i)
	{
		cout << pecasProduzidas[i]; 	
		if (pecasProduzidas[i]->getTipo() == "amarela")
		{
			amarelas++;
			continue;
		}
		if (pecasProduzidas[i]->getTipo() == "azul"){
			azuis++;
			continue;
		}
		vermelhas++;
	}
	cout << amarelas << " peças amarelas, " << azuis << " peças azuis e " << 
	vermelhas << " peças vermelhas." << endl;
	cout << "Total de tempo gasto na produção: " << tempoTotalProducao << " segundos" << endl;
}
*/
void Fabrica::printProducao()
{
	int amarelas = 0,vermelhas = 0 ,azuis = 0;
	
	cout << "Total de Peças produzidas: " << totalPecasProduzidas << endl;
	for (int i = 0; i < totalPecasProduzidas; ++i)
	{
		cout << pecasProduzidas[i] << endl; 	
		if (pecasProduzidas[i]->getTipo() == "amarela")
		{
			amarelas++;
			continue;
		}
		if (pecasProduzidas[i]->getTipo() == "azul"){
			azuis++;
			continue;
		}
		vermelhas++;
	}
	cout << amarelas << " peças amarelas, " << azuis << " peças azuis e " << 
	vermelhas << " peças vermelhas." << endl;
	cout << "Total de tempo gasto na produção: " << getTempoTotalProducao() << " segundos" << endl;
}



