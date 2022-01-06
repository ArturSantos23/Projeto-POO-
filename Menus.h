#pragma once
#include "libs.h"
#include "SistemaFicheiros.h"

class Menus
{
public:
    static int Menu();
    static int MenuSearch();
    static string NomeSearch(int Op);
    static int MenuRemover();
    static string NomeDiretoriaRemover();
    static int MenuTree();
    static void Select(SistemaFicheiros* P);
};

