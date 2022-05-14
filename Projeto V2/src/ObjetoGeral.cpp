#include "ObjetoGeral.h"

ObjetoGeral::ObjetoGeral(tm *_data, string _caminho, string _nome)
{
    DataCriacao = _data;
    Path = _caminho;
    Nome = _nome;
}

ObjetoGeral::~ObjetoGeral()
{
    //dtor
}

void ObjetoGeral::AddTabulacoesXML(ofstream &Ficheiro, int Espacos)
{
    for(int i = 0; i < Espacos; ++i)
        Ficheiro << "\t";
}

void ObjetoGeral::EscreveElementoXML(ofstream &Ficheiro, int Espacos, string Elemento)
{
    AddTabulacoesXML(Ficheiro, Espacos);
    Ficheiro << "<" << Elemento << ">";
}

void ObjetoGeral::FechaElementoXML(ofstream &Ficheiro, int Espacos, string Elemento)
{
    AddTabulacoesXML(Ficheiro, Espacos);
    Ficheiro << "</" << Elemento << ">\n";
}
