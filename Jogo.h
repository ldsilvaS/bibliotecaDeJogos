#pragma once
#include <iostream>

using namespace std;

class Jogo {
private:
	string tituloJogo;
	string tipoJogo;
	int ano;
	double valor;

public:
	Jogo(string _tituloJogo, string _tipoJogo, int _ano, double _valor);
	string getTituloJogo() const;
	void setTituloJogo(string nomeJogo);
	string getTipoJogo() const;
	void setTipoJogo(string tipoJogo);
	int getAno() const;
	void setAno(int ano);
	double getValor() const;
	void setValor(double valor);


};