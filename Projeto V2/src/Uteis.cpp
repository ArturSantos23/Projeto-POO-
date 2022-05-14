#include "Uteis.h"

int Uteis::Menu()
{
    int opcao, opcao_invalida;
    do
    {
        system("cls");
        cout << "#--------------------------------------------------MENU--------------------------------------------------#" << endl;
        cout << "|  1- Carregar uma diretoria                                                                             |" << endl;
        cout << "|  2- Contar o n�mero de ficheiros guardados em mem�ria                                                  |" << endl;
        cout << "|  3- Contar o n�mero de diretorias guardadas em mem�ria                                                 |" << endl;
        cout << "|  4- Determinar toda a mem�ria ocupada                                                                  |" << endl;
        cout << "|  5- Determinar qual a diretoria que tem mais elementos                                                 |" << endl;
        cout << "|  6- Determinar qual a diretoria que tem menos elementos                                                |" << endl;
        cout << "|  7- Determinar qual o ficheiro que ocupa mais espa�o                                                   |" << endl;
        cout << "|  8- Determinar qual a diretoria que ocupa mais espa�o                                                  |" << endl;
        cout << "|  9- Pesquisar ficheiro ou diretoria                                                                    |" << endl;
        cout << "| 10- Remover todos os ficheiros ou todas as diretorias                                                  |" << endl;
        cout << "| 11- Gravar os ficheiros em formato XML                                                                 |" << endl;
        cout << "| 12- Ler XML (apaga todo o Sistema de Ficheiros criado anteriormente)                                   |" << endl;
        cout << "| 13- Mover um ficheiro para outra diretoria                                                             |" << endl;
        cout << "| 14- Mover uma diretoria para outra diretoria (implica mover tudo o que esteja dentro dessa diretoria)  |" << endl;
        cout << "| 15- Inserir o nome de um ficheiro e receber a data de modifica��o                                      |" << endl;
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
            cout << "Opcao n�o dispon�vel! Insira uma op��o v�lida!" << endl;
            system("pause");
        }
        fflush(stdin);
    } while (opcao_invalida);

    return opcao;
}

int Uteis::MenuSearch()
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

string Uteis::NomeSearch(int Op)
{
    string Nome;

    if (Op == 0)
        cout << "Qual o nome do ficheiro a pesquisar?" << endl;
    else
        cout << "Qual o nome da diretoria a pesquisar?" << endl;

    cin >> Nome;
    return Nome;
}

int Uteis::MenuRemover()
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

string Uteis::NomeDiretoriaRemover()
{
    string Nome;
    cout << "Qual o nome da diretoria que pretende eliminar?" << endl;
    cin >> Nome;
    system("cls");
    return Nome;
}

int Uteis::MenuTree()
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

string Uteis::NomeTree()
{
    string Nome;
    cout << "Qual o nome do ficheiro onde quer guardar a tree?" << endl;
    cin >> Nome;
    system("cls");
    return Nome;
}

void Uteis::Select(SistemaFicheiros *P)
{
    int Op, OpAux;
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
            //cout << "Insira o nome da pasta ou o caminho a abrir!" << endl;
            //getline(cin, Str);
            //if(!P->LoadRoot(Str))
            if (!P->LoadRoot("C:/Users/Pedro Guedes/Documents/GitHub/Projeto-POO/Projeto"))
                cout << "Nao foi poss�vel abrir a diretoria!" << endl;
            else
                cout << "Diretoria carregada com �xito!" << endl;

            system("pause");
            break;

        case 2:
            cout << "N�mero de ficheiros guardados em mem�ria: " << P->ContarFicheiros() << endl;
            system("pause");
            break;

        case 3:
            cout << "N�mero de diretorias guardadas em mem�ria: " << P->ContarDirectorias() << endl;
            system("pause");
            break;

        case 4:
            cout << "Estao alocados " << P->Memoria() << " bytes na memoria!" << endl;
            system("pause");
            break;
        case 5:
            cout << "A diretoria com mais elementos �: " << P->DiretoriaMaisElementos() << endl;
            system("pause");
            break;

        case 6:
            cout << "A diretoria com menos elementos �: " << P->DiretoriaMenosElementos() << endl;
            system("pause");
            break;

        case 7:
            cout << "O ficheiro maior �: " << P->FicheiroMaior() << endl;
            system("pause");
            break;

        case 8:
            cout << "A maior diretoria �: " << P->DiretoriaMaisEspaco() << endl;
            system("pause");
            break;

        case 9:
            OpAux = MenuSearch();
            Str = NomeSearch(OpAux);
            cout << "Resultado da procura: " << P->Search(Str, OpAux) << endl;
            system("pause");
            break;

        case 10:
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
            cout << "Qual o nome do ficheiro para o qual pretende guardar o conteudo em XML?" << endl;
            cin >> Str;
            P->Escrever_XML(Str);
            system("pause");
            break;

        case 12:
            cout << "Lemos em XML depois" << endl;
            //Ler_XML();
            system("pause");
            break;

        case 13:
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
            cout << "Movemos directoria depois" << endl;
            //MoverDirectoria();
            system("pause");
            break;

        case 15:
            cout << "Qual o nome do ficheiro do qual pretende saber a data?" << endl;
            cin >> StrAux;
            cout << P->DataFicheiro(StrAux) << endl;
            system("pause");
            break;

        case 16:
            OpAux = MenuTree();
            if (OpAux == 0)
                StrAux = NomeTree();
            else
                StrAux = "-1";

            P->Tree(StrAux);
            system("pause");
            break;

        case 17:
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
            cout << "Qual o nome do(s) ficheiro(s) a renomear?" << endl;
            cin >> Str;
            cout << "Qual o novo nome a inserir?" << endl;
            cin >> StrAux;
            P->RenomearFicheiros(Str, StrAux);
            system("pause");
            break;

        case 20:
            if (P->FicheirosDuplicados())
                cout << "Existem ficheiros duplicados!" << endl;
            else
                cout << "Nao existem ficheiros duplicados!" << endl;
            system("pause");
            break;

        case 21:
            cout << "Copiamos ficheiros de uma directoria para outra depois" << endl;
            //CopyBatch();
            system("pause");
            break;
        }
        if (Op == 0)
            cout << "Adeus!" << endl;
    } while (Op != 0);
}
