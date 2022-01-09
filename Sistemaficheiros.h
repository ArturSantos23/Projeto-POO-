#pragma once
#include "libs.h"
#include "Diretoria.h"
#include "Ficheiro.h"

class SistemaFicheiros
{
    Diretoria* Raiz = NULL; //Enquanto nao for especificada, a Diretoria Raiz sera NULL
    string Path;

    public:
        SistemaFicheiros();
        bool LoadRoot(const string& path);                                                                  //alínea 1 (root)
        bool Load(const string& path, Diretoria* Dir);                                                      //alínea 1
        int ContarFicheiros();                                                                              //alínea 2
        int ContarDirectorias();                                                                            //alínea 3
        int Memoria();                                                                                      //alínea 4
        string DiretoriaMaisElementos();                                                                    //alínea 5
        string DiretoriaMenosElementos();                                                                   //alínea 6
        string FicheiroMaior();                                                                             //alínea 7
        string DiretoriaMaisEspaco();                                                                       //alínea 8
        string Search(const string& s, int Tipo);                                                           //alínea 9
        bool RemoverAll(const string& s, const string& tipo);                                               //alínea 10
        void Escrever_XML(const string& s);                                                                 //alínea 11
        bool Ler_XML(const string& s);                                                                      //alínea 12
        bool MoveFicheiro(const string& Fich, const string& DirNova);                                       //alínea 13
        bool MoverDirectoria(const string& DirOld, const string& DirNew);                                   //alínea 14
        string DataFicheiro(const string& ficheiro);                                                        //alínea 15
        void PesquisarAllDirectorias(list<string>& lres, const string& dir);                                //alínea 17
        void PesquisarAllFicheiros(list<string>& lres, const string& file);                                 //alínea 18
        bool VerificarExistenciaFicheiro(const string& NFich);
        void RenomearFicheiros(const string& fich_old, const string& fich_new);                             //alínea 19
        bool FicheirosDuplicados();                                                                         //alínea 20
        bool CopyBatch(const string& padrao, const string& DirOrigem, const string& DirDestino);            //alínea 21
        virtual ~SistemaFicheiros();
};