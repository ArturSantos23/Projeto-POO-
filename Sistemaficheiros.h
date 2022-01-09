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
        bool LoadRoot(const string& path);                                                                  //al�nea 1 (root)
        bool Load(const string& path, Diretoria* Dir);                                                      //al�nea 1
        int ContarFicheiros();                                                                              //al�nea 2
        int ContarDirectorias();                                                                            //al�nea 3
        int Memoria();                                                                                      //al�nea 4
        string DiretoriaMaisElementos();                                                                    //al�nea 5
        string DiretoriaMenosElementos();                                                                   //al�nea 6
        string FicheiroMaior();                                                                             //al�nea 7
        string DiretoriaMaisEspaco();                                                                       //al�nea 8
        string Search(const string& s, int Tipo);                                                           //al�nea 9
        bool RemoverAll(const string& s, const string& tipo);                                               //al�nea 10
        void Escrever_XML(const string& s);                                                                 //al�nea 11
        bool Ler_XML(const string& s);                                                                      //al�nea 12
        bool MoveFicheiro(const string& Fich, const string& DirNova);                                       //al�nea 13
        bool MoverDirectoria(const string& DirOld, const string& DirNew);                                   //al�nea 14
        string DataFicheiro(const string& ficheiro);                                                        //al�nea 15
        void PesquisarAllDirectorias(list<string>& lres, const string& dir);                                //al�nea 17
        void PesquisarAllFicheiros(list<string>& lres, const string& file);                                 //al�nea 18
        bool VerificarExistenciaFicheiro(const string& NFich);
        void RenomearFicheiros(const string& fich_old, const string& fich_new);                             //al�nea 19
        bool FicheirosDuplicados();                                                                         //al�nea 20
        bool CopyBatch(const string& padrao, const string& DirOrigem, const string& DirDestino);            //al�nea 21
        virtual ~SistemaFicheiros();
};