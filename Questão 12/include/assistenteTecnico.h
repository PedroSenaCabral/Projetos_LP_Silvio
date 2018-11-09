#ifndef ASSTECNICO_H
#define ASSTECNICO_H
#include "funcionario.h"
#include "supervisor.h"
#include <string>
class AssistenteTecnico: public Funcionario{
private:
	float m_bonus_salarial;
	Funcionario *m_supervisor;
public:
	AssistenteTecnico(std::string nome_,int idade_,float altura_, std::string matricula_, float salario_,float bonus_salarial_, Funcionario *supervisor_);
	~AssistenteTecnico();
	float getBonusSalarial();
	void setBonusSalarial(float bonus_salarial_);
	Supervisor* getSupervisor();
	void setSupervisor(Supervisor *supervisor_);
};
#endif