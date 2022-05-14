#pragma once
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include "sys/stat.h"
#include<list>

string Espacos(int N);
bool Processar_DIR(const string& path, int& tam, int N = 0);										//teste
int ContarFicheiros();
int ContarDiretorias();

class Sistemaficheiros
{
public:
	bool Load(const string& path);																	//1
	int Memoria();																					//4
	string DiretoriaMaisElementos();																//5
	string DiretoriaMenosElementos();																//6
	string FicheiroMaior();																			//7
	string DiretoriaMaisEspaco();																	//8
	string Search(const string& s, int Tipo);														//9
	bool RemoverAll(const string& s, const string& tipo);											//10
	void Escrever_XML(const string& s);																//11
	bool Ler_XML(const string& s);																	//12
	bool MoverFicheiro(const string& Fich, const string& DirNova);									//13
	bool MoverDir(const string& DirOld, const string& DirNova);										//14
	string DataFicheiro(const string& ficheiro);													//15
	//void Tree(const string* fich = "tree.txt");													//16
	void PesquisarAllDiretorias(list<string>& Ires, const string& dir);								//17
	void PesquisarAllFicheiros(list<string>& Ires, const string& file);								//18
	void RenomearFicheiros(const string& fich_old, const string& fich_new);							//19
	bool FicheiroDuplicados();																		//20
	bool CopyBatch(const string& padrao, const string& DirOrigem, const string& DirDestino);		//21
};

