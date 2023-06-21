#pragma once
#include <iostream>
#include <vector>
#include "Jogo.h"
#include "Pessoa.h"

using namespace std;

class Usuario :  public Pessoa {
private:
	string email;
	string senha;
	double saldo;
	
	



public:
	Usuario() {};
	Usuario(string nome, string id, string email, string senha, double saldo);
	string getEmail() const;
	void setEmail(string email);
	string getSenha() const;
	void setSenha(string senha);
	double getSaldo() const;
	void setSaldo(double saldo);

	

};
