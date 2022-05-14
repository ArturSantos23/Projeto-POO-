#include "Sistemaficheiros.h"

int main()
{
    //SetCurrentDirectory;
    /*
    int TAM = 0;
    bool RES = Processar_DIR("DirectoriaTeste", TAM);

    cout << "RES = " << RES << " TAM = " << TAM << endl;
    */
    cout << "Teste tree /f" << endl << endl;
    system("tree /f");
    /*
    cout << "Teste tree /a" << endl << endl;
    system("tree /a");
    cout << "Teste tree /f /a" << endl << endl;
    system("tree /f /a");
    */
    //int File_num = ContarFicheiros();
    
    return 0;
}
