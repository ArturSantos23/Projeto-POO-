#include "Ficheiro.h"

Ficheiro::Ficheiro(tm* _data, int _tamanho, string _caminho, string _nome)
	: ObjetoGeral(_data, _caminho, _nome)
{
	Tamanho = _tamanho;
}

Ficheiro::~Ficheiro()
{
	//dtor
}

void Ficheiro::EscreverXML(ofstream& File, int Espacos)
{
	EscreveElementoXML(File, Espacos, "Ficheiro");
	File << "\n";

	EscreveElementoXML(File, Espacos + 1, "Nome");
	File << this->GetNome();
	FechaElementoXML(File, 0, "Nome");

	EscreveElementoXML(File, Espacos + 1, "Path");
	File << this->GetPath();
	FechaElementoXML(File, 0, "Path");

	EscreveElementoXML(File, Espacos + 1, "Tamanho");
	File << this->GetTamanho();
	FechaElementoXML(File, 0, "Tamanho");

	FechaElementoXML(File, Espacos, "Ficheiro");
}