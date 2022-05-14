#ifndef DIRETORIA_H
#define DIRETORIA_H

#include <ObjetoGeral.h>
#include "Ficheiro.h"

class Diretoria : public ObjetoGeral
{
    list<Diretoria *> LDir;
    list<Ficheiro *> LFich;
    public:
        Diretoria(tm *_data, string _caminho, string _nome);
        void AddFich(Ficheiro *Fich){LFich.push_back(Fich);};
        void AddDir(Diretoria *Dir){LDir.push_back(Dir);};
        void ContarFicheiros(int *NumFich);
        void ContarDiretorias(int *NumDir);
        int GetNumFich(){return LFich.size();};
        int GetNumDir(){return LDir.size();};
        void Memoria(int *MemoriaTotal);
        int GetTamanhoDir();
        int GetNumElem(){return LFich.size() + LDir.size();};
        void DirMaisElementos(int *NumElementos, string *DirPath, string *DirName);
        void DirMaisElementosRoot(int *NumElementos, string *DirPath, string *DirName);
        void DirMenosElementos(int *NumElementos, string *DirPath, string *DirName);
        void DirMenosElementosRoot(int *NumElementos, string *DirPath, string *DirName);
        void FichMaior(int *Tamanho, string *FichPath, string *NomePath);
        void DiretoriaMaior(int *Tamanho, string *DirPath, string *NomeDir);
        void DiretoriaMaiorRoot(int *Tamanho, string *DirPath, string *NomeDir);
        void SearchFicheiros(const string &FileName, string &Caminho);
        void Search(const string &DirName, string &Caminho);
        void RemoveFicheiros();
        void RemoveSubDiretorias();
        bool RemoveDiretorias(const string &DirName);
        bool RemoveFicheirosTodos();
        void EscreverXML(ofstream &File, int Espacos);
        Diretoria *GetPonteiroDirFicheiro(const string &NomeFicheiro, Ficheiro *F);
        bool MoveFicheiro(const string& Fich, const string& DirNova);
        tm *DataFicheiros(const string &NomeFich);
        void TreeRoot(int Espacos);
        void TreeRootFich(ofstream &File, int Espacos);
        void Tree(int Espacos);
        void TreeFich(ofstream &File, int Espacos);
        void PesquisarAllDiretorias(list<string> &LNomes, const string &NomeDir);
        void PesquisarAllDiretoriasRoot(list<string> &LNomes, const string &NomeDir);
        void PesquisarAllFicheiros(list<string> &LNomes, const string &NomeFicheiro);
        void RenomearFicheiros(const string& NFich, const string& NNovo);
        void RenomearFicheirosRoot(const string& NFich, const string& NNovo);
        bool VerificaNomes(list<string> &LNomes, string NomeVerificar);
        bool FicheirosDuplicados(list<string> &LNomes);
        virtual ~Diretoria();

    protected:

    private:
};

#endif // DIRETORIA_H
