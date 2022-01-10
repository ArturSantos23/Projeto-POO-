#include "libs.h"
#include "Menus.h"

int Menus::Menu()
{
    int opcao, opcao_invalida = 0;
    do
    {
        system("cls");
        cout << "#--------------------------------------------------MENU--------------------------------------------------#" << endl;
        cout << "|  1- Carregar a diretoria                                                                               |" << endl;
        cout << "|  2- Contar o numero de ficheiros guardados em memoria                                                  |" << endl;
        cout << "|  3- Contar o numero de diretorias guardadas em memoria                                                 |" << endl;
        cout << "|  4- Determinar toda a memoria ocupada                                                                  |" << endl;
        cout << "|  5- Determinar qual a diretoria que tem mais elementos                                                 |" << endl;
        cout << "|  6- Determinar qual a diretoria que tem menos elementos                                                |" << endl;
        cout << "|  7- Determinar qual o ficheiro que ocupa mais espaco                                                   |" << endl;
        cout << "|  8- Determinar qual a diretoria que ocupa mais espaco                                                  |" << endl;
        cout << "|  9- Pesquisar ficheiro ou diretoria                                                                    |" << endl;
        cout << "| 10- Remover ficheiro ou diretoria                                                                      |" << endl;
        cout << "| 11- Gravar os ficheiros em formato XML                                                                 |" << endl;
        cout << "| 12- Ler XML (apaga todo o Sistema de Ficheiros criado anteriormente)                                   |" << endl;
        cout << "| 13- Mover um ficheiro para outra diretoria                                                             |" << endl;
        cout << "| 14- Mover uma diretoria para outra diretoria (move ficheiros e sub-diretorias)                         |" << endl;
        cout << "| 15- Inserir o nome de um ficheiro e receber a data de modificacao                                      |" << endl;
        cout << "| 16- Tree                                                                                               |" << endl;
        cout << "| 17- Pesquisar todas as diretorias                                                                      |" << endl;
        cout << "| 18- Pesquisar todos os ficheiros                                                                       |" << endl;
        cout << "| 19- Renomear ficheiros                                                                                 |" << endl;
        cout << "| 20- Verificar se exitem ficheiros duplicados (com o mesmo nome)                                        |" << endl;
        cout << "| 21- Copiar os ficheiros de uma diretoria para outra, definida pelo utilizador                          |" << endl;
        cout << "| 0 - Sair                                                                                               |" << endl;
        cout << "#--------------------------------------------------------------------------------------------------------#" << endl;
        cin >> opcao;
        opcao_invalida = ((opcao > 21) && (opcao < 0));

        if (opcao_invalida)
        {
            cout << "Opcao nao disponivel! Insira uma opcao valida!" << endl;
            system("pause");
        }
        fflush(stdin);
    } while (opcao_invalida);

    return opcao;
}

int Menus::MenuSearch()
{
    int opcao, opcao_invalida;
    do
    {
        system("cls");
        cout << "#--------------------------------------------------MENU--------------------------------------------------#" << endl;
        cout << "|  0 - Procurar um ficheiro                                                                              |" << endl;
        cout << "|  1 - Procurar uma diretoria                                                                            |" << endl;
        cout << "#--------------------------------------------------------------------------------------------------------#" << endl;
        cin >> opcao;
        opcao_invalida = !((opcao == 1) || (opcao == 0));

        if (opcao_invalida)
        {
            cout << "Opcao invalida! Insira uma das opcoes apresentadas!" << endl;
            system("pause");
        }
        fflush(stdin);
    } while (opcao_invalida);

    return opcao;
}

string Menus::NomeSearch(int Op)
{
    string Nome;

    if (Op == 0)
        cout << "Qual o nome do ficheiro a pesquisar?" << endl;
    else
        cout << "Qual o nome da diretoria a pesquisar?" << endl;

    cin >> Nome;
    return Nome;
}

int Menus::MenuRemover()
{
    int opcao, opcao_invalida;
    do
    {
        system("cls");
        cout << "#--------------------------------------------------MENU--------------------------------------------------#" << endl;
        cout << "|  0 - Remover todos os Ficheiros                                                                        |" << endl;
        cout << "|  1 - Remover uma Diretoria (incluido as sub-diretorias e os respetivos ficheiros)                      |" << endl;
        cout << "#--------------------------------------------------------------------------------------------------------#" << endl;
        cin >> opcao;
        opcao_invalida = !((opcao == 1) || (opcao == 0));

        if (opcao_invalida)
        {
            cout << "Opcao invalida! Insira uma das opcoes apresentadas!" << endl;
            system("pause");
        }
        fflush(stdin);
    } while (opcao_invalida);
    system("cls");
    return opcao;
}

string Menus::RemoverDiretoria()
{
    string Nome;
    cout << "Qual o nome da diretoria que pretende eliminar?" << endl;
    cin >> Nome;
    system("cls");
    return Nome;
}

int Menus::MenuTree()
{
    int opcao, opcao_invalida;
    do
    {
        system("cls");
        cout << "#--------------------------------------------------MENU--------------------------------------------------#" << endl;
        cout << "|  0 - Mostrar Tree num ficheiro                                                                         |" << endl;
        cout << "|  1 - Mostrar Tree no ecra                                                                              |" << endl;
        cout << "#--------------------------------------------------------------------------------------------------------#" << endl;
        cin >> opcao;
        opcao_invalida = !((opcao == 1) || (opcao == 0));

        if (opcao_invalida)
        {
            cout << "Opcao invalida! Insira uma das opcoes apresentadas!" << endl;
            system("pause");
        }
        fflush(stdin);
    } while (opcao_invalida);
    system("cls");
    return opcao;
}

void Menus::Select(SistemaFicheiros* P)
{
    int Opcao, OpAux, aux_loaded = 0;
    char buff[PATH_MAX];
    _getcwd(buff, PATH_MAX);    //faz o catch da diretoria atual do programa
    string current_dir(buff);
    string Str, StrAux, confirmar, del_dir, old_filename, new_filename, old_dirname, new_dirname;
    list<string> LResDir;
    list<string> LResFich;

    do
    {
        system("cls");
        Opcao = Menu();
        switch (Opcao)
        {
            do
            {
            case 1:
                //if (!P->LoadRoot("C:/Users/artur/Desktop/Artur/2� Ano Engenharia Inform�tica/1� Semestre/Programacao Orientada a Objetos/Projeto/DirectoriaTeste"))
                if (!P->LoadRoot(current_dir))  //faz load da directoria onde o programa se encontra
                {
                    cout << "Nao foi possivel abrir a diretoria!" << endl;
                }
                else
                {
                    cout << "Diretoria carregada com exito!" << endl;
                    cout << "Foi carregada a seguinte diretoria: " << current_dir << endl;
                    aux_loaded = 1;
                }
                system("pause");
                break;

            case 2:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    cout << "Numero de ficheiros guardados em memoria: " << P->ContarFicheiros() << endl;
                    system("pause");
                }
                break;

            case 3:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    cout << "Numero de diretorias guardadas em memoria: " << P->ContarDirectorias() << endl;
                    system("pause");
                }
                break;

            case 4:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    cout << "Estao alocados " << P->Memoria() << " bytes na memoria!" << endl;
                    system("pause");
                }
                break;

            case 5:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    cout << "A diretoria com mais elementos e: " << P->DiretoriaMaisElementos() << endl;
                    system("pause");
                }
                break;

            case 6:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    cout << "A diretoria com menos elementos e: " << P->DiretoriaMenosElementos() << endl;
                    system("pause");
                }
                break;

            case 7:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    cout << "O ficheiro maior e: " << P->FicheiroMaior() << endl;
                    system("pause");
                }
                break;

            case 8:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    cout << "A maior diretoria e: " << P->DiretoriaMaisEspaco() << endl;
                    system("pause");
                }
                break;

            case 9:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    OpAux = MenuSearch();
                    Str = NomeSearch(OpAux);
                    cout << "Resultado da procura: " << P->Search(Str, OpAux) << endl;
                    system("pause");
                }
                break;

            case 10:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    OpAux = MenuRemover();
                    if (OpAux == 1)
                    {
                        del_dir = RemoverDiretoria();
                        P->RemoverAll(del_dir, "DIR");
                    }
                    else
                        P->RemoverAll("-", "Fich");
                    system("pause");
                }
                break;

            case 11:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    cout << "Qual o nome do ficheiro para o qual pretende guardar o conteudo em XML?" << endl;
                    cin >> Str;
                    P->Escrever_XML(Str);
                    system("pause");
                }
                break;

            case 12:
                //Ler_XML();
                system("pause");
                break;

            case 13:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    system("cls");
                    cout << endl << "Qual o nome do ficheiro que pretende mover?" << endl;
                    cin >> old_filename;
                    cin.ignore();
                    if (P->VerificarExistenciaFicheiro(old_filename))   //Verifica se o ficheiro especificado pelo utilizador existe na diretoria atual
                    {
                        cout << endl << "A mover o ficheiro: <" << old_filename << "> da diretoria: " << current_dir << endl;
                        cout << endl << "Qual o caminho da diretoria para a qual pretende mover?" << endl;
                        cin >> new_dirname;
                        if (P->VerificarExistenciaDiretoria(new_dirname))        //Verificar se existe a diretoria especificada pelo utilizador
                        {
                            cout << "Deseja fazer a seguinte operacao? [Sim/Nao] :" << endl << "Mover o ficheiro <" << old_filename << "> da diretoria " << current_dir << "para a diretoria " << new_dirname << endl;
                            cin >> confirmar;
                            if (confirmar == "s" || confirmar == "S" || confirmar == "sim" || confirmar == "Sim" || confirmar == "SIM" || confirmar == "y" || confirmar == "Y" || confirmar == "yes" || confirmar == "Yes" || confirmar == "YES")
                            {
                                if (P->MoveFicheiro(old_filename, current_dir, new_dirname))   //move o ficheiro indicado pelo utilizar da diretoria "old_dirname" para a diretoria "new_dirname"
                                        cout << endl << "O ficheiro <" << old_filename << "> " << "foi movido para a diretoria " << new_dirname << endl << endl;
                                system("pause");
                            }
                            else
                            {
                                cout << "Operacao cancelada" << endl << endl << "A sair......." << endl;
                                system("pause");
                                break;
                             }  
                        }
                    }
                    else if(!P->VerificarExistenciaFicheiro(old_filename))  //Caso o ficheiro especificado pelo utilizador n�o exista na diretoria atual
                    {
                        cout << endl << "O ficheiro que esta a mover nao se encontra na mesma diretoria do programa" << endl;
                        cout << "Por favor indique o caminho da diretoria do ficheiro que pretende mover:" << endl; //O utilizador tem de especificar para que diretoria pretende mover o ficheiro
                        cin >> old_dirname;
                        if (P->VerificarExistenciaDiretoria(old_dirname))   //Verificar se existe a diretoria especificada pelo utilizador
                        {
                            cout << endl << "A mover o ficheiro: <" << old_filename << "> da diretoria: " << old_dirname << endl;
                            cout << endl << "Qual o caminho da diretoria para a qual pretende mover?" << endl;
                            cin >> new_dirname;
                            if (P->VerificarExistenciaDiretoria(new_dirname))   //Verificar se existe a diretoria especificada pelo utilizador
                            {
                                cout << endl << "Deseja fazer a seguinte operacao? [Sim/Nao] :" << endl << "Mover o ficheiro <" << old_filename << "> da diretoria " << old_dirname << "para a diretoria " << new_dirname << endl;
                                cin >> confirmar;
                                if (confirmar == "s" || confirmar == "S" || confirmar == "sim" || confirmar == "Sim" || confirmar == "SIM" || confirmar == "y" || confirmar == "Y" || confirmar == "yes" || confirmar == "Yes" || confirmar == "YES")
                                {
                                    if (P->MoveFicheiro(old_filename, old_dirname, new_dirname))   //move o ficheiro indicado pelo utilizador da diretoria "old_dirname" para a diretoria "new_dirname"
                                        cout << endl << "O ficheiro <" << old_filename << "> " << "foi movido para a diretoria " << new_dirname << endl << endl;
                                    system("pause");
                                }
                                else
                                {
                                    cout << "Operacao cancelada" << endl << endl << "A sair......." << endl;
                                    system("pause");
                                    break;
                                }
                            }
                        }
                    }
                }
                break;

            case 14:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    system("cls");
                    cout << endl << "Indique o caminho da diretoria que pretende mover" << endl;
                    cin >> old_dirname;
                    cin.ignore();
                    if (P->VerificarExistenciaDiretoria(old_dirname))   //Verificar se existe a diretoria especificada pelo utilizador
                    {
                        cout << endl << "A mover a diretoria: " << old_dirname << endl;
                        cout << endl << "Indique o novo caminho para onde pretende mover a diretoria" << endl;
                        cin >> new_dirname;
                        if (P->VerificarExistenciaDiretoria(new_dirname))   //Verificar se existe a diretoria especificada pelo utilizador
                        {
                            cout << endl << "Deseja fazer a seguinte operacao? [Sim/Nao] :" << endl << "Mover a diretoria " << old_dirname << " para a diretoria " << new_dirname << endl;
                            cin >> confirmar;
                            if (confirmar == "s" || confirmar == "S" || confirmar == "sim" || confirmar == "Sim" || confirmar == "SIM" || confirmar == "y" || confirmar == "Y" || confirmar == "yes" || confirmar == "Yes" || confirmar == "YES")
                            {
                                if (P->MoverDirectoria(old_dirname, new_dirname))   //Move a diretoria indicada pelo utilizador para uma outra diretoria "new_dirname"
                                {
                                    cout << endl << "Operacao concluida com sucesso" << endl << endl;
                                    cout << "Mostrar a tree? [Sim/Nao] :" << endl;  //(extra) Mostra a tree para verificar mudan�as
                                    cin >> confirmar;
                                    if (confirmar == "s" || confirmar == "S" || confirmar == "sim" || confirmar == "Sim" || confirmar == "SIM" || confirmar == "y" || confirmar == "Y" || confirmar == "yes" || confirmar == "Yes" || confirmar == "YES")
                                    {
                                        cout << endl << endl;
                                        system("tree /f");
                                    }
                                }
                                system("pause");
                            }
                            else
                            {
                                cout << "Operacao cancelada" << endl << endl << "A sair......." << endl;
                                system("pause");
                                break;
                            }
                        }
                    }
                }
                break;

            case 15:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    cout << "Qual o nome do ficheiro do qual pretende saber a data?" << endl;
                    cin >> StrAux;
                    cout << P->DataFicheiro(StrAux) << endl;
                    system("pause");
                }
                break;

            case 16:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    OpAux = MenuTree();
                    if (OpAux == 0)
                    {
                        system("tree /f /a > tree.txt");    //guarda a tree do path atual para um ficheiro (tree.txt)
                        cout << endl << "Tree guardada no ficheiro: <tree.txt>" << endl << endl;
                    }
                    else
                        system("tree /f");                  //mostra a tree do path atual no ecr�

                    system("pause");
                }
                break;

            case 17:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    cout << "Qual o nome da(s) diretoria(s) a pesquisar?" << endl;
                    cin >> Str;
                    P->PesquisarAllDirectorias(LResDir, Str);
                    cout << "Resultados obtidos:" << endl;
                    for (list<string>::iterator it = LResDir.begin(); it != LResDir.end(); ++it)
                        cout << (*it) << endl;
                    LResDir.clear();
                    system("pause");
                }
                break;

            case 18:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    cout << "Qual o nome do(s) ficheiro(s) a pesquisar?" << endl;
                    cin >> Str;
                    P->PesquisarAllFicheiros(LResFich, Str);
                    cout << "Resultados obtidos:" << endl;
                    for (list<string>::iterator it = LResFich.begin(); it != LResFich.end(); ++it)
                        cout << (*it) << endl;
                    LResFich.clear();
                    system("pause");
                }
                break;

            case 19:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    cout << "Qual o nome do(s) ficheiro(s) a renomear?" << endl;
                    cin.ignore(); //Ignora o numero de caracteres que o user epecificar quando a fun��o � chamada
                    cin >> old_filename;
                    if (P->VerificarExistenciaFicheiro(old_filename))
                    {
                        cout << "Qual o novo nome a inserir?" << endl;
                        cin >> new_filename;
                        P->RenomearFicheiros(old_filename, new_filename);   //renomeia em "mem�ria" (para efeitos de pesquisa atrav�s do uso das listas)
                        rename(old_filename.c_str(), new_filename.c_str()); //renomeia o ficheiro "fisicamente"
                        system("pause");
                        
                    }
                    else
                    {
                        cout << "[ERRO!!]: Nao foi possivel renomear o ficheiro <" << old_filename << ">. O ficheiro nao existe ou pertence a outra diretoria." << endl;
                        cout << endl << "Tente novamente por favor." << endl;
                        system("pause");
                        break;
                    }
                }
                break;

            case 20:
                if (aux_loaded == 0)
                {
                    cout << "ERRO! N�o foi poss�vel carregar a directoria" << endl;
                    system("pause");
                }
                else
                {
                    if (P->FicheirosDuplicados())
                        cout << "Existem ficheiros duplicados!" << endl;
                    else
                        cout << "Nao existem ficheiros duplicados!" << endl;
                    system("pause");
                }
                break;

            case 21:
                //CopyBatch();
                system("pause");
                break;

            } while (aux_loaded == 0);
        }
        if (Opcao == 0)
            cout << "Adeus!" << endl;
        else if(Opcao < 0 || Opcao > 21)
        {
            cout << "Insira uma opcao valida" << endl;
            system("pause");
        }
    } while (Opcao != 0);
}
