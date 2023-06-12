#include <iostream>
#include "Conta.h"

using namespace std;

Conta::Conta(string agencia, double saldo){
	this->agencia = agencia;
	this->saldo = saldo;
}

double Conta::getSaldo() const {
	return saldo;
}

void Conta::setSaldo(double saldo) {
	saldo = saldo;
}

string Conta::getAgencia() const {
	return agencia;
}

void Conta::setAgencia(string agencia) {
	agencia = agencia;
}