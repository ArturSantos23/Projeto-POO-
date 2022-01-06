#include "libs.h"
#include "SistemaFicheiros.h"
#include "Menus.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    /*Teste de memoria
        while(1)
        {
            SistemaFicheiros *SF = new SistemaFicheiros();
            SF->LoadRoot(current_dir);
            delete SF;
        }
    */

    SistemaFicheiros* F = new SistemaFicheiros();
    Menus::Select(F);

    return 0;
}