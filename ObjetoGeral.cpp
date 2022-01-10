#include "ObjetoGeral.h"

ObjetoGeral::ObjetoGeral(tm* _data, string _caminho, string _nome)
{
    DataCriacao = _data;
    Path = _caminho;
    Nome = _nome;
}

ObjetoGeral::~ObjetoGeral()
{
    //dtor
}

void ObjetoGeral::AddTabulacoesXML(ofstream& Ficheiro, int Espacos)
{
    for (int i = 0; i < Espacos; ++i)
        Ficheiro << "\t";
}

void ObjetoGeral::EscreveElementoXML(ofstream& Ficheiro, int Espacos, string Elemento)
{
    AddTabulacoesXML(Ficheiro, Espacos);
    Ficheiro << "<" << Elemento << ">";
}

void ObjetoGeral::FechaElementoXML(ofstream& Ficheiro, int Espacos, string Elemento)
{
    AddTabulacoesXML(Ficheiro, Espacos);
    Ficheiro << "</" << Elemento << ">\n";
}

tm* ObjetoGeral::GetData(const string& NFich)
{
    stat(NFich.c_str(), &attrib_file);
    DataCriacao = gmtime(&(attrib_file.st_mtime));
    return DataCriacao;
}