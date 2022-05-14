#ifndef UTEIS_H
#define UTEIS_H

#include "main.h"
#include "SistemaFicheiros.h"
class Uteis
{
    public:
        static int Menu();
        static int MenuSearch();
        static string NomeSearch(int Op);
        static int MenuRemover();
        static string NomeDiretoriaRemover();
        static int MenuTree();
        static string NomeTree();
        static void Select(SistemaFicheiros *P);
};

#endif // UTEIS_H
