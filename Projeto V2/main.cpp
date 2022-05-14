#include "main.h"
#include "SistemaFicheiros.h"
#include "Uteis.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

/*Teste de memoria
    while(1)
    {
        SistemaFicheiros *SF = new SistemaFicheiros();
        SF->LoadRoot("C:/Users/Pedro Guedes/Documents");
        delete SF;
    }
*/

    SistemaFicheiros* F = new SistemaFicheiros();
    Uteis::Select(F);

    return 0;
}
