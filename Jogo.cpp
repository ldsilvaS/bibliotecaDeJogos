#include "Jogo.h"
#include <iostream>

using namespace std;

Jogo::Jogo(string _tituloJogo, string _tipoJogo, int _ano, double _valor) {
	tituloJogo = _tituloJogo;
	tipoJogo = _tipoJogo;
	ano = _ano;
	valor = _valor;

}

string Jogo::getTituloJogo() const { return tituloJogo; }

void Jogo::setTituloJogo(string _tituloJogo) { tituloJogo = _tituloJogo; }

string Jogo::getTipoJogo() const { return tipoJogo; }

void Jogo::setTipoJogo(string _tipoJogo) { tipoJogo = _tipoJogo; }

int Jogo::getAno() const { return ano; }

void Jogo::setAno(int _ano) { ano = _ano; }

double Jogo::getValor() const { return valor; }

void Jogo::setValor(double _valor) { valor = _valor; }