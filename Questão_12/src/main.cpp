#include "pessoa.h"
#include "funcionario.h"
#include "gerente.h"
#include "oficina.h"
#include "assistenteTecnico.h"
#include "assistenteAdministrativo.h"
#include <iostream>

using namespace std ;

int main (int argc , char const * argv []){
	//Criando Gerente e oficina
	Gerente *gerente = new Gerente("Carlos",19,1.80, "2010110033",10000);
	Oficina *oficina = new Oficina(gerente);
	//Criando os Funcionarios
	AssistenteAdministrativo * AssAdm1 = new AssistenteAdministrativo("Pedro",22,1.84, "2017123456",2000,"noite",0.1);
	AssistenteAdministrativo * AssAdm2 = new AssistenteAdministrativo("Joice",21,1.65, "2017112233",2000,"noite",0.1);
	AssistenteTecnico * AssTec1 = new AssistenteTecnico("João",25,1.70, "2017338484", 1000.0,500.0,AssAdm1);
	AssistenteTecnico * AssTec2 = new AssistenteTecnico("Maria",30,1.80, "2017010101", 1000.0,500.0,AssAdm2);
	
	//Adicionando Funcionarios na oficina
	oficina->addFuncionario(AssAdm1);
	oficina->addFuncionario(AssAdm2);
	oficina->addFuncionario(AssTec1);
	oficina->addFuncionario(AssTec2);
	cout <<oficina;
return 0;
}