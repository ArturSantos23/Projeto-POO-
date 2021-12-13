#include "Sistemaficheiros.h"

bool Sistemaficheiros::Load(const string& path)
{
	return false;
}

int Sistemaficheiros::ContarFicheiros()
{
	return 0;
}

int Sistemaficheiros::ContarDiretorias()
{
	return 0;
}

int Sistemaficheiros::Memoria()
{
	return 0;
}

string Sistemaficheiros::DiretoriaMaisElementos()
{
	return string();
}

string Sistemaficheiros::DiretoriaMenosElementos()
{
	return string();
}

string Sistemaficheiros::FicheiroMaior()
{
	return string();
}

string Sistemaficheiros::DiretoriaMaisEspaco()
{
	return string();
}

string Sistemaficheiros::Search(const string& s, int Tipo)
{
	return string();
}

bool Sistemaficheiros::RemoverAll(const string& s, const string& tipo)
{
	return false;
}

void Sistemaficheiros::Escrever_XML(const string& s)
{
}

bool Sistemaficheiros::Ler_XML(const string& s)
{
	return false;
}

bool Sistemaficheiros::MoverFicheiro(const string& Fich, const string& DirNova)
{
	return false;
}

bool Sistemaficheiros::MoverDir(const string& DirOld, const string& DirNova)
{
	return false;
}

string Sistemaficheiros::DataFicheiro(const string& ficheiro)
{
	return string();
}
/*
void Sistemaficheiros::Tree(const string* fich)
{
	return;
}
*/
void Sistemaficheiros::PesquisarAllDiretorias(list<string>& Ires, const string& dir)
{
}

void Sistemaficheiros::PesquisarAllFicheiros(list<string>& Ires, const string& file)
{
}

void Sistemaficheiros::RenomearFicheiros(const string& fich_old, const string& fich_new)
{
}

bool Sistemaficheiros::FicheiroDuplicados()
{
	return false;
}

bool Sistemaficheiros::CopyBatch(const string& padrao, const string& DirOrigem, const string& DirDestino)
{
	return false;
}
