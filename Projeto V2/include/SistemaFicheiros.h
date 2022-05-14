#ifndef SISTEMAFICHEIROS_H
#define SISTEMAFICHEIROS_H

#include "main.h"
#include "Diretoria.h"
#include "Ficheiro.h"
class SistemaFicheiros
{
    Diretoria *Raiz = NULL; //Enquanto nao for especificada, a Diretoria Raiz sera NULL
    string Path;

    public:
        SistemaFicheiros();
        bool LoadRoot(const string &path);
        bool Load(const string &path, Diretoria *Dir);
        int ContarFicheiros();
        int ContarDirectorias();
        int Memoria();
        string DiretoriaMaisElementos();
        string DiretoriaMenosElementos();
        string FicheiroMaior();
        string DiretoriaMaisEspaco();
        string Search(const string &s, int Tipo);
        bool RemoverAll(const string& s, const string& tipo);
        void Escrever_XML(const string &s);
        bool Ler_XML(const string &s);
        bool MoveFicheiro(const string& Fich, const string& DirNova);
        bool MoverDirectoria(const string& DirOld, const string& DirNew);
        string DataFicheiro(const string& ficheiro);
        void Tree(const string &fich = "tree.txt");
        void PesquisarAllDirectorias(list<string>& lres, const string& dir);
        void PesquisarAllFicheiros(list<string>& lres, const string& file);
        void RenomearFicheiros(const string& fich_old, const string& fich_new);
        bool FicheirosDuplicados();
        bool CopyBatch(const string& padrao, const string& DirOrigem, const string& DirDestino);
        virtual ~SistemaFicheiros();
};

#endif // SISTEMAFICHEIROS_H
