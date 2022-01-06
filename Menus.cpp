#include "libs.h"
#include "Menus.h"

int Menus::Menu()
{
    int opcao, opcao_invalida = 0;
    do
    {
        system("cls");
        cout << "#--------------------------------------------------MENU--------------------------------------------------#" << endl;
        cout << "|  1- Carregar uma diretoria                                                                             |" << endl;
        cout << "|  2- Contar o numero de ficheiros guardados em memoria                                                  |" << endl;
        cout << "|  3- Contar o numero de diretorias guardadas em memoria                                                 |" << endl;
        cout << "|  4- Determinar toda a memoria ocupada                                                                  |" << endl;
        cout << "|  5- Determinar qual a diretoria que tem mais elementos                                                 |" << endl;
        cout << "|  6- Determinar qual a diretoria que tem menos elementos                                                |" << endl;
        cout << "|  7- Determinar qual o ficheiro que ocupa mais espaco                                                   |" << endl;
        cout << "|  8- Determinar qual a diretoria que ocupa mais espaco                                                  |" << endl;
        cout << "|  9- Pesquisar ficheiro ou diretoria                                                                    |" << endl;
        cout << "| 10- Remover todos os ficheiros ou todas as diretorias                                                  |" << endl;
        cout << "| 11- Gravar os ficheiros em formato XML                                                                 |" << endl;
        cout << "| 12- Ler XML (apaga todo o Sistema de Ficheiros criado anteriormente)                                   |" << endl;
        cout << "| 13- Mover um ficheiro para outra diretoria                                                             |" << endl;
        cout << "| 14- Mover uma diretoria para outra diretoria (implica mover tudo o que esteja dentro dessa diretoria)  |" << endl;
        cout << "| 15- Inserir o nome de um ficheiro e receber a data de modificacao                                      |" << endl;
        cout << "| 16- Tree                                                                                               |" << endl;
        cout << "| 17- Pesquisar diretorias                                                                               |" << endl;
        cout << "| 18- Pesquisar ficheiros                                                                                |" << endl;
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
        cout << "|  1 - Remover uma Diretoria (incluido as sub-diretorias e os respetivos ficheiros                       |" << endl;
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

string Menus::NomeDiretoriaRemover()
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
    int Op, OpAux;
    char buff[PATH_MAX];
    _getcwd(buff, PATH_MAX);
    string current_dir(buff);
    string Str, StrAux;
    list<string> LResDir;
    list<string> LResFich;

    do
    {
        system("cls");
        Op = Menu();
        switch (Op)
        {
        case 1:
            //if (!P->LoadRoot("C:/Users/artur/Desktop/Artur/2º Ano Engenharia Informática/1º Semestre/Programacao Orientada a Objetos/Projeto/DirectoriaTeste"))
            if (!P->LoadRoot(current_dir))
                cout << "Nao foi possivel abrir a diretoria!" << endl;
            else
                cout << "Diretoria carregada com exito!" << endl;
            cout << "Foi carregada a seguinte diretoria: " << current_dir << endl;

            system("pause");
            break;

        case 2:
            //fazer verificação se LoadRoot foi executado
            cout << "Numero de ficheiros guardados em memoria: " << P->ContarFicheiros() << endl;
            system("pause");
            break;

        case 3:
            //fazer verificação se LoadRoot foi executado
            cout << "Numero de diretorias guardadas em memoria: " << P->ContarDirectorias() << endl;
            system("pause");
            break;

        case 4:
            //fazer verificação se LoadRoot foi executado
            cout << "Estao alocados " << P->Memoria() << " bytes na memoria!" << endl;
            system("pause");
            break;

        case 5:
            //fazer verificação se LoadRoot foi executado
            cout << "A diretoria com mais elementos e: " << P->DiretoriaMaisElementos() << endl;
            system("pause");
            break;

        case 6:
            //fazer verificação se LoadRoot foi executado
            cout << "A diretoria com menos elementos e: " << P->DiretoriaMenosElementos() << endl;
            system("pause");
            break;

        case 7:
            //fazer verificação se LoadRoot foi executado
            cout << "O ficheiro maior e: " << P->FicheiroMaior() << endl;
            system("pause");
            break;

        case 8:
            //fazer verificação se LoadRoot foi executado
            cout << "A maior diretoria e: " << P->DiretoriaMaisEspaco() << endl;
            system("pause");
            break;

        case 9:
            //fazer verificação se LoadRoot foi executado
            OpAux = MenuSearch();
            Str = NomeSearch(OpAux);
            cout << "Resultado da procura: " << P->Search(Str, OpAux) << endl;
            system("pause");
            break;

        case 10:                                        //Esta a dar erro
            OpAux = MenuRemover();
            if (OpAux == 1)
            {
                Str = NomeDiretoriaRemover();
                P->RemoverAll(Str, "DIR");
            }
            else
                P->RemoverAll(".", "Fich");
            cout << "Eliminacao concluida!" << endl;
            system("pause");
            break;

        case 11:
            //fazer verificação se LoadRoot foi executado
            cout << "Qual o nome do ficheiro para o qual pretende guardar o conteudo em XML?" << endl;
            cin >> Str;
            P->Escrever_XML(Str);
            system("pause");
            break;

        case 12:
            cout << "Por fazer" << endl;
            //cout << "Lemos em XML depois" << endl;
            //Ler_XML();
            system("pause");
            break;

        case 13:
            cout << "Por fazer" << endl;
            //                cout << "Qual o nome do ficheiro que pretende mover?" << endl;
            //                cin >> Str;
            //
            //                cout << "Qual o nome da diretoria para a qual pretende mover?" << endl;
            //                cin >> StrAux;
            //                if(P->MoveFicheiro(Str, StrAux))
            //                    cout << "Movido com sucesso!" << endl;
            //                else
            //                    cout << "Erro a mover!" << endl;
            system("pause");
            break;

        case 14:
            cout << "Por fazer" << endl;
            // cout << "Movemos directoria depois" << endl;
            //MoverDirectoria();
            system("pause");
            break;

        case 15:
            //fazer verificação se LoadRoot foi executado
            cout << "Qual o nome do ficheiro do qual pretende saber a data?" << endl;
            cin >> StrAux;
            cout << P->DataFicheiro(StrAux) << endl;
            system("pause");
            break;

        case 16:
            OpAux = MenuTree();
            if (OpAux == 0)
                system("tree /f /a > tree.txt");    //guarda a tree do path atual para um ficheiro (tree.txt)
            else
                system("tree /f");                  //mostra a tree dath atual no ecrã

            system("pause");
            break;

        case 17:
            //fazer verificação se LoadRoot foi executado
            cout << "Qual o nome da(s) diretoria(s) a pesquisar?" << endl;
            cin >> Str;
            system("cls");
            P->PesquisarAllDirectorias(LResDir, Str);
            cout << "Resultados obtidos:" << endl;
            for (list<string>::iterator it = LResDir.begin(); it != LResDir.end(); ++it)
                cout << (*it) << endl;
            LResDir.clear();
            system("pause");
            break;

        case 18:
            //fazer verificação se LoadRoot foi executado
            cout << "Qual o nome do(s) ficheiro(s) a pesquisar?" << endl;
            cin >> Str;
            system("cls");
            P->PesquisarAllFicheiros(LResFich, Str);
            cout << "Resultados obtidos:" << endl;
            for (list<string>::iterator it = LResFich.begin(); it != LResFich.end(); ++it)
                cout << (*it) << endl;
            LResFich.clear();
            system("pause");
            break;

        case 19:
            /*
            //fazer verificação se LoadRoot foi executado
            Está só a renomear em memória, e não "fisicamente". O ficheiro não é renomeado!!!
            */
            cout << "Qual o nome do(s) ficheiro(s) a renomear?" << endl;
            cin >> Str;
            cout << "Qual o novo nome a inserir?" << endl;
            cin >> StrAux;
            P->RenomearFicheiros(Str, StrAux);
            system("pause");
            break;

        case 20:
            //fazer verificação se LoadRoot foi executado
            if (P->FicheirosDuplicados())
                cout << "Existem ficheiros duplicados!" << endl;
            else
                cout << "Nao existem ficheiros duplicados!" << endl;
            system("pause");
            break;

        case 21:
            cout << "Por fazer" << endl;
            //cout << "Copiamos ficheiros de uma directoria para outra depois" << endl;
            //CopyBatch();
            system("pause");
            break;
        }
        if (Op == 0)
            cout << "Adeus!" << endl;
    } while (Op != 0);
}
