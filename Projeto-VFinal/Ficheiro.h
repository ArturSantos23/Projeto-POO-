#pragma once
#include "ObjetoGeral.h"

class Ficheiro :
	public ObjetoGeral
{
	int Tamanho;

public:
	Ficheiro(tm* _data, int _tamanho, string _caminho, string _nome);
	int GetTamanho() { return Tamanho; };
	void EscreverXML(ofstream& File, int Espacos);
	virtual ~Ficheiro();
};