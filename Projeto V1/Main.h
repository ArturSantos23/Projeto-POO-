#pragma once

inline int main()
{
    cout << "Teste Main" << endl << endl;
    //SetCurrentDirectory;
    /*
    int TAM = 0;
    bool RES = Processar_DIR("DirectoriaTeste", TAM);

    cout << "RES = " << RES << " TAM = " << TAM << endl;
    */

    //system("tree c://");
    int File_num;
    File_num = Sistemaficheiros::ContarFicheiros();
    cout << "Numero de ficheiros = " << File_num << endl;


    Sistemaficheiros::ContarDiretorias();

    return 0;
}
