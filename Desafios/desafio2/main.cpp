#include "Pilha.h"

#include <iostream>

#include <string>
#include <cmath>


int realizaOperacao(char operacao, double valor1, double valor2) {
	double resultado = 0;
	switch (operacao) {
		case ('+'):
			resultado = valor1 + valor2;
			break;

		case ('-'):
			resultado = valor1 - valor2;
			break;

		case ('*'):
			resultado = valor1 * valor2;
			break;

		case ('/'):
			resultado = valor1 / valor2;
			break;

		default:
			cout << "Operação invalida.";
			exit(0);
	}

	return resultado;
}

int main(int argc, char const *argv[])
{

	Pilha<int> pilha(50);
	string notacao;

	cout << "Insira a expressão no formado Notação Polonesa Inversa: ";

	cin.ignore(0, '\n');
	getline(cin, notacao);



	for (unsigned int i = 0; i < notacao.length(); i++) {
		string aux = "";

		
		while (notacao[i] != ' ' && i < notacao.length()) { // lê cada caracter da string e contatena em 'aux' até encontrar um espaço
			aux += notacao[i];
			i++;
		}

		if (aux[0] == '+' || aux[0] == '-' || aux[0] == '*' || aux[0] == '/' ) { // Se a leitura do while foi uma operação
			
			// realiza alguma operação;
			double a = pilha.desempilhar();
			double b = pilha.desempilhar();

			// Os operandos tem que estar invertidos ao  desempilhar. 
			// Assim evita algo do tipo: 10/5 -> 10 5 / ** empilha 10 **> pilha[10] **empilha 5**> pilha[10, 5] ** Desempilhar**> 5 / 10 
			cout << "\nRealizando Operação: " << b << aux << a << " = "<< realizaOperacao(aux[0], b, a) << endl; 
			
			pilha.empilhar(realizaOperacao(aux[0], b, a));

		} else { // Se a leitura do while foi um número

			pilha.empilhar(stoi(aux));
		 	cout << "Empilhando Valor: " << aux << endl;
		
		}

	}

	cout << "O resultado da operação é: " << pilha.desempilhar();
		
	return 0;
}