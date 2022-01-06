#include "SistemaFicheiros.h"

SistemaFicheiros::SistemaFicheiros()
{
    //ctor
}

SistemaFicheiros::~SistemaFicheiros()
{
    delete Raiz;
}

bool SistemaFicheiros::LoadRoot(const string& path)
{
    bool Resultado = false;
    DIR* fich = NULL;
    if (((fich = opendir(path.c_str())) != NULL))
    {
        struct dirent* abrir = readdir(fich);
        this->Path = path;
        Diretoria* D = new Diretoria(NULL, path, abrir->d_name);
        this->Raiz = D;

        if (!Load(path, D))
            Resultado = false;
        else
            Resultado = true;

        closedir(fich);
    }
    return Resultado;
}

bool SistemaFicheiros::Load(const string& path, Diretoria* Dir)
{
    bool Resultado = false;
    DIR* fich = NULL;
    if (((fich = opendir(path.c_str())) != NULL))
    {
        struct tm* DataCriacao;
        struct stat status;
        struct dirent* abrir;
        while ((abrir = readdir(fich)))
        {
            if ((strcmp(abrir->d_name, ".") != 0) && (strcmp(abrir->d_name, "..") != 0))
            {
                string p = path;
                p.append("/");
                p.append(abrir->d_name);
                stat(p.c_str(), &status);
                if (S_ISDIR(status.st_mode)) // Diretoria
                {
                    DataCriacao = gmtime(&status.st_ctime);
                    Diretoria* D = new Diretoria(DataCriacao, path, abrir->d_name);
                    Dir->AddDir(D);
                    Load(p, D);
                }
                else if (S_ISREG(status.st_mode)) //Ficheiro
                {
                    DataCriacao = gmtime(&status.st_ctime);
                    Ficheiro* F = new Ficheiro(DataCriacao, status.st_size, path, abrir->d_name);
                    Dir->AddFich(F);
                }
            }
            Resultado = true;
        }

        closedir(fich);
    }
    return Resultado;
}

int SistemaFicheiros::ContarFicheiros()
{
    int NumFich = 0;
    this->Raiz->ContarFicheiros(&NumFich);
    return NumFich;
}

int SistemaFicheiros::ContarDirectorias()
{
    int NumDir = 0;
    this->Raiz->ContarDiretorias(&NumDir);
    return NumDir;
}

int SistemaFicheiros::Memoria()
{
    int MemoriaTotal = 0;
    MemoriaTotal = MemoriaTotal + sizeof(SistemaFicheiros);
    this->Raiz->Memoria(&MemoriaTotal);
    return MemoriaTotal;
}

string SistemaFicheiros::DiretoriaMaisElementos()
{
    string DirPath;
    string DirName;
    int NumElementos = 0;
    this->Raiz->DirMaisElementosRoot(&NumElementos, &DirPath, &DirName);
    cout << DirName << " e tem: " << NumElementos << " elementos! O seu caminho ?: ";
    return(DirPath);
}

string SistemaFicheiros::DiretoriaMenosElementos()
{
    string DirPath;
    string DirName;
    int NumElementos = 10000;
    this->Raiz->DirMenosElementosRoot(&NumElementos, &DirPath, &DirName);
    cout << DirName << " e tem: " << NumElementos << " elementos! O seu caminho ?: ";
    return(DirPath);
}

string SistemaFicheiros::FicheiroMaior()
{
    string FilePath;
    string FileName;
    int Tamanho = 0;
    this->Raiz->FichMaior(&Tamanho, &FilePath, &FileName);
    cout << FileName << " e ocupa: " << Tamanho << " bytes! O seu caminho ?: ";
    return(FilePath);
}

string SistemaFicheiros::DiretoriaMaisEspaco()
{
    string DirPath;
    string DirName;
    int Tamanho = 0;
    this->Raiz->DiretoriaMaiorRoot(&Tamanho, &DirPath, &DirName);
    cout << DirName << " e ocupa: " << Tamanho << " bytes! O seu caminho ?: ";
    return(DirPath);
}

string SistemaFicheiros::Search(const string& s, int Tipo)
{
    string Caminho = "Nao encontrado";

    if (Tipo == 0)
        this->Raiz->SearchFicheiros(s, Caminho);

    if (Tipo == 1)
        this->Raiz->Search(s, Caminho);

    return Caminho;
}

bool SistemaFicheiros::RemoverAll(const string& s, const string& tipo)
{
    bool Resultado = false;

    if (tipo.compare("DIR") == 0)
        Resultado = this->Raiz->RemoveDiretorias(s);
    else
        Resultado = this->Raiz->RemoveFicheirosTodos();

    return Resultado;
}

void SistemaFicheiros::Escrever_XML(const string& s)
{
    ofstream File;
    File.open(s);
    if (!File)
    {
        cout << "Erro na abertura do ficheiro em " << __FUNCTION__ << endl;
        return;
    }

    File << "<SistemaFicheiros>\n" << endl;
    this->Raiz->EscreverXML(File, 0);
    File << "</SistemaFicheiros>\n" << endl;
    File.close();

}

bool SistemaFicheiros::Ler_XML(const string& s)
{
    return false;
}

bool SistemaFicheiros::MoveFicheiro(const string& Fich, const string& DirNova)
{
    //return this->Raiz->MoveFicheiro(Fich, DirNova);
    return false;
}

bool SistemaFicheiros::MoverDirectoria(const string& DirOld, const string& DirNew)
{
    return false;
}

string SistemaFicheiros::DataFicheiro(const string& ficheiro)
{
    tm* Data = this->Raiz->DataFicheiros(ficheiro);
    string resultado;
    if (Data != NULL)
    {
        resultado = ": Data de criacao do ficheiro <";
        resultado.append(ficheiro).append(">");
        cout << Data->tm_mday << "/" << Data->tm_mon << "/" << Data->tm_year + 1900;
        return resultado;
    }
    else
        return "Ficheiro nao encontrado!";
}

void SistemaFicheiros::PesquisarAllDirectorias(list<string>& lres, const string& dir)
{
    this->Raiz->PesquisarAllDiretoriasRoot(lres, dir);
}

void SistemaFicheiros::PesquisarAllFicheiros(list<string>& lres, const string& file)
{
    this->Raiz->PesquisarAllFicheiros(lres, file);
}

void SistemaFicheiros::RenomearFicheiros(const string& fich_old, const string& fich_new)
{
    this->Raiz->RenomearFicheiros(fich_old, fich_new);
    cout << "O(s) ficheiro(s) ja foi/foram renomeados" << endl;
}

bool SistemaFicheiros::FicheirosDuplicados()
{
    list<string> LNomes; //Pouca rapidez quando existem muitos ficheiros!
    bool Resultado = false;
    Resultado = this->Raiz->FicheirosDuplicados(LNomes);
    return Resultado;
}

bool SistemaFicheiros::CopyBatch(const string& padrao, const string& DirOrigem, const string& DirDestino)
{
    return false;
}
