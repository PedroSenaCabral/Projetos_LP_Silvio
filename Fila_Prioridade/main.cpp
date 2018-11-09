#include "fila_prioridade.h"

#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main()
{

	pair<int, string> pessoas[5];

	pessoas[0]= make_pair(1, "Dennis");
	pessoas[1]= make_pair(5, "Joao");
	pessoas[2]= make_pair(7, "Maria");
	pessoas[3]= make_pair(8, "Jose");
	pessoas[4]= make_pair(4, "Pedro");
	pessoas[5]= make_pair(11, "Ferreira");

	Fila_Prioridade< pair <int, string> > fila_do_caixa(5);

	cout<<"\nVerificando a fila...\n";
	if(fila_do_caixa.vazia()){
		cout<<"A Fila esta vazia!"<<endl;
	}else{
		cout<<"A Fila nao esta vazia!"<<endl;
	}

	cout<<"Tamanho da Fila: "<<fila_do_caixa.tamanho()<<endl;

	cout<<"\nAdicionando pessoas na fila..."<<endl;
	fila_do_caixa.enfileira(pessoas[0]);
	fila_do_caixa.enfileira(pessoas[1]);
	fila_do_caixa.enfileira(pessoas[2]);
	fila_do_caixa.enfileira(pessoas[3]);
	fila_do_caixa.enfileira(pessoas[4]);

	cout<<"\nVerificando a fila...\n";
	if(fila_do_caixa.cheia()){
		cout<<"A Fila esta cheia!"<<endl;
	}else{
		cout<<"Fila nao esta cheia!"<<endl;
	}

	cout<<"Tamanho da Fila: "<<fila_do_caixa.tamanho()<<endl;

	cout<<"\nAdicionando pessoas na fila..."<<endl;
	try{
		fila_do_caixa.enfileira(pessoas[5]);
	}catch(int e){
		cout<<"Nao foi possivel adicionar na fila. A Fila esta cheia."<<endl;
	}

	cout<<"\nChamando pessoas da fila..."<<endl;
	while(!fila_do_caixa.vazia()){

		pair<int, string> pessoa= fila_do_caixa.desenfileira();

		cout<<"Proximo da Fila: "<<pessoa.second
			<<" - Prioridade: "<<pessoa.first<<endl;
	}

	cout<<"\nChamando o proximo da fila..."<<endl;

	try{
		cout<<"\nProximo da Fila: "<<fila_do_caixa.desenfileira().second;
	}catch(int e){
		cout<<"A Fila esta vazia!"<<endl;
	}
	

	return 0;

}