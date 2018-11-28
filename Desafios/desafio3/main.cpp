#include <stack>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	
	/**
	*	Inicia a pilha e a fila
	*/
	stack<int> pilha; // Auxilia no calculo do valor em decimal, armazenando o valor menos significativos no todo da pilha
	queue<int> fila; // Auxicila na exibição do numero binario, enfileirando os números na ordem de exibição
	int valor, cont = 0, total = 0;


	cout<<"Digite um valor binario"<<endl;
	do{
		// Lê o valor 0 ou 1 do número binario (Qualquer outro para a leitura e calcula o resultado)
		cin >> valor;
		
		if(valor > 1){
			break;
		}

		// Adiciona os valores na pilha e na fila
		pilha.push(valor);
		fila.push(valor);


	} while(valor == 0 || valor == 1);

	/**
	*	Calcula o total em decimal
	*/
	while(!pilha.empty()){

		/**
		* Desenpilha o valor, calcula o valor (1, 2, 4, 8, 16 ...) com base no valor do cont
		*/
		total += pilha.top() * (pow(2,cont));
		cont++;

		pilha.pop(); // retira o elemento da pilha

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