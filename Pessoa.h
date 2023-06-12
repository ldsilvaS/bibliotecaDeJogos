#pragma once
#include <iostream>

using namespace std;

class Pessoa {
private:
	string nome;
	string id;

public:
	Pessoa() {};
	Pessoa(string nome, string id);
	string getNome() const;
	void setNome(string nome);
	string getId() const;
	void setId(string id);
};