#include <iostream>
#include "fila.h"

using namespace std;

int main()
{

	Fila<int> fila(10);

	for(int i=1; i<=10; i++)
	{
		fila.enfileira(i);
	}

	for(int i=1; i<=10; i++)
	{
		cout<<"Proximo: "<<fila.desenfileira()<<endl;
	}


	return 0;


}