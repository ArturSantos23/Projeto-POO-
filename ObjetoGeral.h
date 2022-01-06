#pragma once
#include "libs.h"

class Diretoria;
class ObjetoGeral
{
    struct tm* DataCriacao;
    string Nome;
    string Path;
public:
    ObjetoGeral(tm* _data, string _caminho, string _nome);
    string GetNome() { return Nome; };
    string GetPath() { return Path; };
    void AddTabulacoesXML(ofstream& Ficheiro, int Espacos);
    void EscreveElementoXML(ofstream& Ficheiro, int Espacos, string Elemento);
    void FechaElementoXML(ofstream& Ficheiro, int Espacos, string Elemento);
    tm* GetData() { return DataCriacao; };
    void AtualizaPath(const string& NovoPath) { Path = NovoPath; };
    void Renomear(const string& NomeNovo) { Nome = NomeNovo; };
    virtual ~ObjetoGeral();

};