#pragma once
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<list>

class Sistemaficheiros
{
	bool Load(const string& path);
	int ContarFicheiros();
	int ContarDiretorias();
	int Memoria();
	string DiretoriaMaisElementos();
	string DiretoriaMenosElementos();
	string FicheiroMaior();
	string DiretoriaMaisEspaco();
	string Search(const string& s, int Tipo);
	bool RemoverAll(const string& s, const string& tipo);
	void Escrever_XML(const string& s);
	bool Ler_XML(const string& s);
	bool MoverFicheiro(const string& Fich, const string& DirNova);
	bool MoverDir(const string& DirOld, const string& DirNova);
	string DataFicheiro(const string& ficheiro);
	//void Tree(const string* fich = "tree.txt");
	void PesquisarAllDiretorias(list<string>& Ires, const string& dir);
	void PesquisarAllFicheiros(list<string>& Ires, const string& file);
	void RenomearFicheiros(const string& fich_old, const string& fich_new);
	bool FicheiroDuplicados();
	bool CopyBatch(const string& padrao, const string& DirOrigem, const string& DirDestino);
};