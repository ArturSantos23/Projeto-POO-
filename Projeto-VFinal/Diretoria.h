#pragma once
#include "ObjetoGeral.h"
#include "Ficheiro.h"

class Diretoria :
	public ObjetoGeral
{
	list<Diretoria*> LDir;
	list<Ficheiro*> LFich;

public:
	Diretoria(tm* _data, string _caminho, string _nome);
	void AddFich(Ficheiro* Fich) { LFich.push_back(Fich); };
	void AddDir(Diretoria* Dir) { LDir.push_back(Dir); };
	void ContarFicheiros(int* NumFich);
	void ContarDiretorias(int* NumDir);
	int GetNumFich() { return LFich.size(); };
	int GetNumDir() { return LDir.size(); };
	void Memoria(int* MemoriaTotal);
	int GetTamanhoDir();
	int GetNumElem() { return LFich.size() + LDir.size(); };
	void DirMaisElementos(int* NumElementos, string* DirPath, string* DirName);
	void DirMaisElementosRoot(int* NumElementos, string* DirPath, string* DirName);
	void DirMenosElementos(int* NumElementos, string* DirPath, string* DirName);
	void DirMenosElementosRoot(int* NumElementos, string* DirPath, string* DirName);
	void FichMaior(int* Tamanho, string* FichPath, string* NomePath);
	void DiretoriaMaior(int* Tamanho, string* DirPath, string* NomeDir);
	void DiretoriaMaiorRoot(int* Tamanho, string* DirPath, string* NomeDir);
	void SearchFicheiros(const string& FileName, string& Caminho);
	void Search(const string& DirName, string& Caminho);
	bool RemoveDiretoria(const string& DirName);
	bool RemoveFicheiros(const string& Path);
	void EscreverXML(ofstream& File, int Espacos);
	bool MoveFicheiro(const string& Fich, string DirAntiga, string DirNova);
	bool MoverDirectoria(const string& DirOld, const string& DirNew);
	tm* DataFicheiro(const string& NomeFich);
	void PesquisarAllDiretorias(list<string>& LNomes, const string& NomeDir);
	void PesquisarAllDiretoriasRoot(list<string>& LNomes, const string& NomeDir);
	void PesquisarAllFicheiros(list<string>& LNomes, const string& NomeFicheiro);
	void RenomearFicheiros(const string& NFich, const string& NNovo);
	void RenomearFicheirosRoot(const string& NFich, const string& NNovo);
	bool VerificaNomes(list<string>& LNomes, string NomeVerificar);
	bool FicheirosDuplicados(list<string>& LNomes);
	bool CopyBatch(const string& padrao, const string& DirOrigem, const string& DirDestino);
	virtual ~Diretoria();
};