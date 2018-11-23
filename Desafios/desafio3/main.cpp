#include <stack>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	
	stack<int> pilha;
	queue<int> fila;
	int valor, cont = 0, total = 0;

	cout<<"Digite um valor binario"<<endl;
	do{

		cin >> valor;
		
		if(valor > 1){
			break;
		}

		pilha.push(valor);
		fila.push(valor);


	} while(valor == 0 || valor == 1);

	while(!pilha.empty()){
		total += pilha.top() * (pow(2,cont));
		cont++;
		pilha.pop();

	}
	cout<<"Numero binario: ";
	while(!fila.empty()){
		cout<<fila.front();
		fila.pop();
	}

	cout<<endl;
	cout<<"Valor total: "<<total<<endl;

	return 0;
}