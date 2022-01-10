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
		struct stat attrib_file;
		struct dirent* abrir;
		while ((abrir = readdir(fich)))
		{
			if ((strcmp(abrir->d_name, ".") != 0) && (strcmp(abrir->d_name, "..") != 0))
			{
				string p = path;
				p.append("\\");
				p.append(abrir->d_name);
				stat(p.c_str(), &attrib_file);
				if (S_ISDIR(attrib_file.st_mode)) // Diretoria
				{
					DataCriacao = gmtime(&attrib_file.st_ctime);
					Diretoria* D = new Diretoria(DataCriacao, path, abrir->d_name);
					Dir->AddDir(D);
					Load(p, D);
				}
				else if (S_ISREG(attrib_file.st_mode)) //Ficheiro
				{
					DataCriacao = gmtime(&attrib_file.st_ctime);
					Ficheiro* F = new Ficheiro(DataCriacao, attrib_file.st_size, path, abrir->d_name);
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
	cout << DirName << endl << "Tem: " << NumElementos << " elementos" << endl << "Caminho: ";
	return(DirPath);
}

string SistemaFicheiros::DiretoriaMenosElementos()
{
	string DirPath;
	string DirName;
	int NumElementos = 10000;
	this->Raiz->DirMenosElementosRoot(&NumElementos, &DirPath, &DirName);
	cout << DirName << endl << "Tem: " << NumElementos << " elementos" << endl << "Caminho: ";
	return(DirPath);
}

string SistemaFicheiros::FicheiroMaior()
{
	string FilePath;
	string FileName;
	int Tamanho = 0;
	this->Raiz->FichMaior(&Tamanho, &FilePath, &FileName);
	cout << FileName << endl << "Ocupa: " << Tamanho << " bytes." << endl << "Caminho: ";
	return(FilePath);
}

string SistemaFicheiros::DiretoriaMaisEspaco()
{
	string DirPath;
	string DirName;
	int Tamanho = 0;
	this->Raiz->DiretoriaMaiorRoot(&Tamanho, &DirPath, &DirName);
	cout << DirName << endl << "Ocupa: " << Tamanho << " bytes." << endl << "Caminho: ";
	return(DirPath);
}

string SistemaFicheiros::Search(const string& s, int Tipo)
{
	string Caminho = "Nao encontrado";

	if (Tipo == 1)
		this->Raiz->SearchFicheiros(s, Caminho);

	if (Tipo == 2)
		this->Raiz->Search(s, Caminho);

	return Caminho;
}

bool SistemaFicheiros::RemoverAll(const string& s, const string& tipo)
{
	bool Resultado = false;

	if (tipo.compare("DIR") == 0)
		Resultado = this->Raiz->RemoveDiretoria(s);
	else
		Resultado = this->Raiz->RemoveFicheiros(s);

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

bool SistemaFicheiros::VerificarExistenciaFicheiro(const string& NFich)
{
	if (FILE* fich = fopen(NFich.c_str(), "r"))
	{
		fclose(fich);
		return true;
	}
}

bool SistemaFicheiros::VerificarExistenciaDiretoria(const string& NDir)
{
	struct stat buffer;

	if (stat(NDir.c_str(), &buffer) != 0)
	{
		cout << endl << "[ERRO!!]: A diretoria com o nome " << NDir << " nao foi encontrada" << endl << endl;
		cout << "Insira uma diretoria valida!" << endl << "Usage (Exemplo): C:\\Users\\user\\...\\...\\...\\...\\DirectoriaTeste" << endl << endl;
		system("pause");
		return false;
	}
	else
	{
		return true;
	}
}

bool SistemaFicheiros::MoveFicheiro(const string& Fich, string DirAntiga, string DirNova)   //È necessário adicionar a DirAntiga caso o ficheiro não esteja presente na diretoria carregada em memória 
																							//Se estiver na diretoria carregada em memória ("current_dir" no caso), segue com a funçao sem ter de especificar o path onde o fich se encontra
{
	return this->Raiz->MoveFicheiro(Fich, DirAntiga, DirNova);
}

bool SistemaFicheiros::MoverDirectoria(const string& DirOld, const string& DirNew)
{
	return this->Raiz->MoverDirectoria(DirOld, DirNew);
}

string SistemaFicheiros::DataFicheiro(const string& ficheiro)
{
	tm* Data = this->Raiz->DataFicheiro(ficheiro);
	string resultado;
	if (Data != NULL)
	{
		// years since 1900         // months since January - [0, 11]
		cout << "Data de criacao do ficheiro <" << ficheiro << ">: " << Data->tm_year + 1900 << "|" << Data->tm_mon + 1 << "|" << Data->tm_mday;
		return "";
	}
	else
		return "Ficheiro nao encontrado!";
}

void SistemaFicheiros::Tree()
{
	system("tree /f");  //mostra a tree do path atual no ecrã
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
	cout << "O(s) ficheiro(s) com o nome <" << fich_old << "> foi/foram renomeado(s) para: <" << fich_new << ">" << endl;
}

bool SistemaFicheiros::FicheirosDuplicados()
{
	list<string> LNomes;
	bool Resultado = false;
	Resultado = this->Raiz->FicheirosDuplicados(LNomes);
	return Resultado;
}

bool SistemaFicheiros::CopyBatch(const string& padrao, const string& DirOrigem, const string& DirDestino)
{
	this->Raiz->CopyBatch(padrao, DirOrigem.c_str(), DirDestino);
	return false;
}