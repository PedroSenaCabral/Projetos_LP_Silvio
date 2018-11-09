#ifndef INGRESSO_H
#define INGRESSO_H

#include <iostream>

using namespace std;

class Ingresso{
    protected:
        float m_valor; 
        float m_imposto;

    public:
        Ingresso(float valor_, float imposto_);
        ~Ingresso();
        float getTotal();
        float getImposto();

    friend ostream& operator<< (ostream &o, Ingresso &i);

};

class IngressoVIP : public Ingresso{
  private:
    float m_adicional;

  public:
    IngressoVIP(float adicional_, float valor_, float imposto_);
    ~IngressoVIP();
    float getAdicional();

    friend ostream& operator<< (ostream &o, IngressoVIP &i);
    
};

#endif