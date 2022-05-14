#ifndef FICHEIRO_H
#define FICHEIRO_H

#include <ObjetoGeral.h>


class Ficheiro : public ObjetoGeral
{
    int Tamanho;
    public:
        Ficheiro(tm *_data, int _tamanho, string _caminho, string _nome);
        void Tree(string str, int Espacos);
        void TreeFich(string str, int Espacos, ofstream &File);
        int GetTamanho(){return Tamanho;};
        void EscreverXML(ofstream &File, int Espacos);
        virtual ~Ficheiro();

    protected:

    private:
};

#endif // FICHEIRO_H
