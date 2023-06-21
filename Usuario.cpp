#include "Usuario.h"
#include "Pessoa.h"
#include <iostream>

using namespace std;

Usuario::Usuario(string nome, string id, string email, string senha, double saldo) : Pessoa(nome, id) {
    this->email = email;
    this->senha = senha;
    this->saldo = saldo;
    
}

string Usuario::getEmail() const { 
    return email;
}


void Usuario::setEmail(string email) {
    this->email = email;
}

string Usuario::getSenha() const {
    return senha;
}

void Usuario::setSenha(string senha) {
    this->senha = senha;
}


double Usuario::getSaldo() const {
    return saldo;
}

void Usuario::setSaldo(double saldo) {
    this->saldo = saldo;
}






