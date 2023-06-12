#include "Pessoa.h"
#include <iostream>

using namespace std;

Pessoa::Pessoa(string nome, string id) {
	this->nome = nome;
	this->id = id;
}

string Pessoa::getNome() const { return nome; }

void Pessoa::setNome(string nome) { this->nome = nome; }

string Pessoa::getId() const { return id; }

void Pessoa::setId(string id) { this->id = id; }