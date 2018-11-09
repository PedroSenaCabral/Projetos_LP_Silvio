#ifndef ASSADMINISTRATIVO_H
#define ASSADMINISTRATIVO_H
#include "funcionario.h"
#include <string>
using namespace std;
class AssistenteAdministrativo: public Funcionario{
private:
	string m_turno;
	float m_participacao;
public:
	AssistenteAdministrativo(string nome_,int idade_,float altura_, string matricula_, float salario_,string turno_,float participacao_);
	~AssistenteAdministrativo();
	string getTurno();
	void setTurno(string turno_);
	float getParticipacao();
	void setParticipacao(float participacao_);
};
#endif