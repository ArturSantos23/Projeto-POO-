#include "Diretoria.h"

Diretoria::Diretoria(tm *_data, string _caminho, string _nome)
    : ObjetoGeral(_data, _caminho, _nome)
{
    //ctor
}

Diretoria::~Diretoria()
{
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
        delete *it;

    for (list<Ficheiro *>::iterator it = LFich.begin(); it != LFich.end(); ++it)
        delete *it;
}

void Diretoria::ContarFicheiros(int *NumFich)
{
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
        (*it)->ContarFicheiros(NumFich);

    for (list<Ficheiro *>::iterator it2 = LFich.begin(); it2 != LFich.end(); ++it2)
        *NumFich = *NumFich + 1;
}

void Diretoria::ContarDiretorias(int *NumDir)
{
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
    {
        *NumDir = *NumDir + 1;
        (*it)->ContarDiretorias(NumDir);
    }
}

void Diretoria::Memoria(int *MemoriaTotal)
{
    *MemoriaTotal = *MemoriaTotal + sizeof(Diretoria) + sizeof(Ficheiro) * this->GetNumFich();
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
        (*it)->Memoria(MemoriaTotal);
}

//Nao se tem em conta o que existe dentro de outras diretorias, caso existam
void Diretoria::DirMaisElementos(int *NumElementos, string *DirPath, string *DirName)
{
    if (*NumElementos < this->GetNumElem())
    {
        *NumElementos = this->GetNumElem();
        *DirPath = this->GetPath();
        *DirName = this->GetNome();
    }

    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
    {
        *NumElementos = *NumElementos + this->GetNumElem();
        (*it)->DirMaisElementos(NumElementos, DirPath, DirName);
    }
}

void Diretoria::DirMaisElementosRoot(int *NumElementos, string *DirPath, string *DirName)
{
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
    {
        (*it)->DirMaisElementos(NumElementos, DirPath, DirName);
    }
}

void Diretoria::DirMenosElementos(int *NumElementos, string *DirPath, string *DirName)
{
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
    {
        *NumElementos = *NumElementos + this->GetNumElem();
        (*it)->DirMenosElementos(NumElementos, DirPath, DirName);
    }

    if (*NumElementos > this->GetNumElem())
    {
        *NumElementos = this->GetNumElem();
        *DirPath = this->GetPath();
        *DirName = this->GetNome();
    }
}

void Diretoria::DirMenosElementosRoot(int *NumElementos, string *DirPath, string *DirName)
{
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
    {
        (*it)->DirMenosElementos(NumElementos, DirPath, DirName);
    }
}

void Diretoria::FichMaior(int *Tamanho, string *FichPath, string *NomeFich)
{
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
        (*it)->FichMaior(Tamanho, FichPath, NomeFich);

    for (list<Ficheiro *>::iterator it2 = LFich.begin(); it2 != LFich.end(); ++it2)
    {
        if ((*it2)->GetTamanho() > *Tamanho)
        {
            *Tamanho = (*it2)->GetTamanho();
            *FichPath = (*it2)->GetPath();
            *NomeFich = (*it2)->GetNome();
        }
    }
}

int Diretoria::GetTamanhoDir()
{
    int Tamanho_Total = 0;
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
        Tamanho_Total = (*it)->GetTamanhoDir();

    for (list<Ficheiro *>::iterator it2 = LFich.begin(); it2 != LFich.end(); ++it2)
        Tamanho_Total = Tamanho_Total + (*it2)->GetTamanho();

    return Tamanho_Total;
}

void Diretoria::DiretoriaMaior(int *Tamanho, string *DirPath, string *NomeDir)
{
    if (*Tamanho < this->GetTamanhoDir())
    {
        *Tamanho = this->GetTamanhoDir();
        *DirPath = this->GetPath();
        *NomeDir = this->GetNome();
    }

    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
    {
        (*it)->DiretoriaMaior(Tamanho, DirPath, NomeDir);
    }
}

void Diretoria::DiretoriaMaiorRoot(int *NumElementos, string *DirPath, string *DirName)
{
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
    {
        (*it)->DirMenosElementos(NumElementos, DirPath, DirName);
    }
}

void Diretoria::SearchFicheiros(const string &FileName, string &Caminho)
{
    for (list<Ficheiro *>::iterator it = LFich.begin(); it != LFich.end(); ++it)
    {
        if ((*it)->GetNome().compare(FileName) == 0)
        {
            Caminho = (*it)->GetPath();
            return;
        }
    }
    for (list<Diretoria *>::iterator it2 = LDir.begin(); it2 != LDir.end(); ++it2)
        (*it2)->SearchFicheiros(FileName, Caminho);
}

void Diretoria::Search(const string &DirName, string &Caminho)
{
    if (this->GetNome().compare(DirName) == 0)
    {
        Caminho = this->GetPath();
        return;
    }
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
        (*it)->Search(DirName, Caminho);
}

void Diretoria::RemoveFicheiros()
{
    this->LFich.erase(LFich.begin(), LFich.end());
}

void Diretoria::RemoveSubDiretorias()
{
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); it++)
        (*it)->RemoveSubDiretorias();

    if (LFich.size() != 0)
        this->RemoveFicheiros();
    if (LDir.size() != 0)
        this->LDir.erase(LDir.begin(), LDir.end());
    delete this;
    return;
}

bool Diretoria::RemoveDiretorias(const string &DirName)
{
    if (this->GetNome().compare(DirName) == 0)
    {
        if (this->LDir.size() != 0)
            this->RemoveSubDiretorias();
        if (this->LFich.size() != 0)
            this->RemoveFicheiros();
        return true;
    }

    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
    {
        if ((*it)->RemoveDiretorias(DirName))
        {
            LDir.remove(*it);
            delete *it;
        }
    }
    return false;
}

bool Diretoria::RemoveFicheirosTodos()
{
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
        (*it)->RemoveFicheirosTodos();
    if (this->LFich.size() != 0)
    {
        this->RemoveFicheiros();
        return true;
    }
    return false;
}

void Diretoria::EscreverXML(ofstream &File, int Espacos)
{
    EscreveElementoXML(File, Espacos, "Diretoria");
    File << "\n";

    EscreveElementoXML(File, Espacos + 1, "Nome");
    File << this->GetNome();
    FechaElementoXML(File, 0, "Nome");

    EscreveElementoXML(File, Espacos + 1, "Path");
    File << this->GetPath();
    FechaElementoXML(File, 0, "Path");

    if (this->GetNumDir() != 0)
    {
        EscreveElementoXML(File, Espacos + 1, "LDir");
        File << "\n";
        for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
            (*it)->EscreverXML(File, Espacos + 1);
        FechaElementoXML(File, Espacos + 1, "LDir");
    }

    if (this->GetNumFich() != 0)
    {
        EscreveElementoXML(File, Espacos + 1, "LFich");
        File << "\n";
        for (list<Ficheiro *>::iterator it = LFich.begin(); it != LFich.end(); ++it)
            (*it)->EscreverXML(File, Espacos + 2);
        FechaElementoXML(File, Espacos + 1, "LFich");
    }

    FechaElementoXML(File, Espacos, "Diretoria");
}
// --------------------------> Esta com erros <--------------------------

//Diretoria *Diretoria::GetPonteiroDirFicheiro(const string &NomeFicheiro, Ficheiro *F)
//{
//    for(list<Ficheiro *>::iterator it = LFich.begin(); it != LFich.end(); ++it)
//    {
//        if((*it)->GetNome().compare(NomeFicheiro) == 0)
//        {
//            F = *it;
//            return this;
//        }
//    }
//    for(list<Diretoria *>::iterator it2 = LDir.begin(); it2 != LDir.end(); ++it2)
//        (*it2)->GetPonteiroDirFicheiro(NomeFicheiro, F);
//}
//
//bool Diretoria::MoveFicheiro(const string& Fich, const string& DirNova)
//{
//    int Resultado = false;
//    cout << __FUNCTION__ << " Fich = " << Fich << " DirNova = " << DirNova << endl;
//
//    if(this->GetNome().compare(DirNova) == 0) //Esta na diretoria para onde quer mover
//    {
//        for(list<Ficheiro *>::iterator it = LFich.begin(); it != LFich.end(); ++it)
//        {
//            if((*it)->GetNome().compare(Fich))
//                return Resultado;
//        }
//
//        Ficheiro *F = NULL;
//        Diretoria *DirFich = NULL;
//        DirFich = GetPonteiroDirFicheiro(Fich, F);
//
//        if(!DirFich)
//            return false;
//        if(!F)
//            return false;
//
//        this->LFich.push_back(F);
//        cout << "Entrei aqui!" << endl;
//        F->AtualizaPath(this->GetPath().append("/").append(DirNova));
//        cout << "Entrei aqui!" << endl;
//        DirFich->LFich.remove(F);
//        return true;
//    }
//
//    for(list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
//        (*it)->MoveFicheiro(Fich, DirNova);
//    return Resultado;
//}

tm *Diretoria::DataFicheiros(const string &NomeFich)
{
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
    {
        (*it)->DataFicheiros(NomeFich);
    }

    for (list<Ficheiro *>::iterator it2 = LFich.begin(); it2 != LFich.end(); ++it2)
    {
        if ((*it2)->GetNome().compare(NomeFich) == 0)
            return ((*it2)->GetData());
    }
    return NULL;
}

void Diretoria::TreeRoot(int Espacos)
{
    string str;
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
        (*it)->Tree(Espacos + 1);

    for (list<Ficheiro *>::iterator it2 = LFich.begin(); it2 != LFich.end(); ++it2)
        cout << "#" << (*it2)->GetNome() << endl;
}

void Diretoria::TreeRootFich(ofstream &File, int Espacos)
{
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
        (*it)->TreeFich(File, Espacos + 1);

    for (list<Ficheiro *>::iterator it2 = LFich.begin(); it2 != LFich.end(); ++it2)
        File << "#" << (*it2)->GetNome() << endl;
}

void Diretoria::Tree(int Espacos)
{
    string Str, Aux;
    for (int i = 0; i < Espacos - 1; ++i)
    {
        Aux.append("\t");
        Str.append("\t");
    }
    cout << Str << "|" << this->GetNome() << endl;

    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
        (*it)->Tree(Espacos + 1);

    for (list<Ficheiro *>::iterator it2 = LFich.begin(); it2 != LFich.end(); ++it2)
    {
        cout << Aux << "    |__#" << (*it2)->GetNome() << endl;
    }
}

void Diretoria::TreeFich(ofstream &File, int Espacos)
{
    string Str, Aux;
    for (int i = 0; i < Espacos - 1; ++i)
    {
        Aux.append("\t");
        Str.append("\t");
    }
    File << Str << "|" << this->GetNome() << endl;

    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
        (*it)->TreeFich(File, Espacos + 1);

    for (list<Ficheiro *>::iterator it2 = LFich.begin(); it2 != LFich.end(); ++it2)
    {
        File << Aux << "    |__#" << (*it2)->GetNome() << endl;
    }
}

void Diretoria::PesquisarAllDiretorias(list<string> &LPath, const string &NomeDir)
{
    if (this->GetNome().compare(NomeDir) == 0)
    {
        LPath.push_back(this->GetPath());
    }
    for (list<Diretoria *>::iterator it2 = LDir.begin(); it2 != LDir.end(); ++it2)
        (*it2)->PesquisarAllDiretorias(LPath, NomeDir);
}

void Diretoria::PesquisarAllDiretoriasRoot(list<string> &LPath, const string &NomeDir)
{
    for (list<Diretoria *>::iterator it2 = LDir.begin(); it2 != LDir.end(); ++it2)
        (*it2)->PesquisarAllDiretorias(LPath, NomeDir);
}

void Diretoria::PesquisarAllFicheiros(list<string> &LPath, const string &NomeFicheiro)
{
    for (list<Ficheiro *>::iterator it = LFich.begin(); it != LFich.end(); ++it)
    {
        if ((*it)->GetNome().compare(NomeFicheiro) == 0)
            LPath.push_back((*it)->GetPath());
    }

    for (list<Diretoria *>::iterator it2 = LDir.begin(); it2 != LDir.end(); ++it2)
        (*it2)->PesquisarAllFicheiros(LPath, NomeFicheiro);
}

void Diretoria::RenomearFicheiros(const string &NFich, const string &NNovo)
{
    for (list<Ficheiro *>::iterator it = LFich.begin(); it != LFich.end(); ++it)
    {
        if ((*it)->GetNome().compare(NFich) == 0)
            (*it)->Renomear(NNovo);
    }

    for (list<Diretoria *>::iterator it2 = LDir.begin(); it2 != LDir.end(); ++it2)
        (*it2)->RenomearFicheiros(NFich, NNovo);
}

void Diretoria::RenomearFicheirosRoot(const string &NFich, const string &NNovo)
{
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
        (*it)->RenomearFicheiros(NFich, NNovo);
}

bool Diretoria::VerificaNomes(list<string> &LNomes, string NomeVerificar)
{
    if (LNomes.size() == 0)
        return false;

    for (list<string>::iterator it = LNomes.begin(); it != LNomes.end(); ++it)
    {
        if (NomeVerificar.compare((*it)) == 0)
            return true;
    }

    return false;
}

bool Diretoria::FicheirosDuplicados(list<string> &LNomes)
{
    for (list<Diretoria *>::iterator it = LDir.begin(); it != LDir.end(); ++it)
    {
        int Aux = (*it)->FicheirosDuplicados(LNomes);
        if (Aux)
            return true;
    }

    for (list<Ficheiro *>::iterator it2 = LFich.begin(); it2 != LFich.end(); ++it2)
    {
        if (VerificaNomes(LNomes, (*it2)->GetNome()))
            return true;
        LNomes.push_back((*it2)->GetNome());
    }
}
