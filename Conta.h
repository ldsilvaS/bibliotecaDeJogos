#pragma once
#include <iostream>
#include "Pessoa.h"

using namespace std;

class Conta{
private:
	string agencia;
	double saldo;


public:
	Conta(string agencia, double saldo);
	double getSaldo() const;
	void setSaldo(double saldo);
	string getAgencia() const;
	void setAgencia(string agencia);

	void Deposito(double valor) {
		cout << endl << "-> Informe o valor que voce deseja depositar: ";
		cin >> valor;
		while (valor < 0) {
			cout << endl << "-> Informe um valor positivo: ";
			cin >> valor;
		}
		saldo += valor;
	}

	void Compra(int valor) {

	}

};
