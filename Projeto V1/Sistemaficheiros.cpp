#include "Sistemaficheiros.h"


string Espacos(int N)
{
	string s = "";
	for (int i = 0; i < N; i++)
		s.append("\t");
	return s;

}
/*
DIR *dir; struct dirent *diread;
	vector<char *> files;

	if ((dir = opendir("/")) != nullptr) {
		while ((diread = readdir(dir)) != nullptr) {
			files.push_back(diread->d_name);
		}
		closedir (dir);
	} else {
		perror ("opendir");
		return EXIT_FAILURE;
	}

	for (auto file : files) cout << file << "| ";
	cout << endl;

	return EXIT_SUCCESS;
*/
bool Processar_DIR(const string& path, int& tam, int N)
{
	bool RET = true;
	DIR* fich = NULL;
	cout << Espacos(N) << "PROCESSAR DIRECTORIA [" << path << "]" << endl;
	if (((fich = opendir(path.c_str())) != NULL))
	{
		struct stat status;
		struct dirent* abrir;
		while ((abrir = readdir(fich)))
		{
			// Esta linha � para evitar aquelas directorias "." e ".."
			if ((strcmp(abrir->d_name, ".") != 0) && (strcmp(abrir->d_name, "..") != 0))
			{
				string p = path;
				p.append("/");
				p.append(abrir->d_name);
				stat(p.c_str(), &status);

				if (S_ISDIR(status.st_mode))  //if (abrir->d_type == DT_DIR)
				{
					cout << Espacos(N) << "Temos DIRECTORIA [" << abrir->d_name << "]" << endl;
					cout << Espacos(N) << "temos de recursivamente processar as sub-directorias de " << abrir->d_name << endl;
					Processar_DIR(p, tam, N + 1);
				}
				else if (S_ISREG(status.st_mode)) //if (abrir->d_type == DT_REG)
				{
					struct tm* data_info;
					data_info = localtime(&status.st_mtime);
					cout << Espacos(N) << "Temos FICHEIRO [" << abrir->d_name << "]" << endl;
					cout << Espacos(N) << "TAMANHO FICHEIRO: " << status.st_size << endl;
				}
			}
		}
		closedir(fich);
	}
	else
	{
		cout << Espacos(N) << "Nao deu para abrir esta diretoria" << endl;
		RET = false;
	}
	fich = NULL;
	return RET;
}

bool Sistemaficheiros::Load(const string& path)
{
	return false;
}

int ContarFicheiros()
{
	DIR* dp;
	int i = 0;
	struct dirent* ep;
	dp = opendir("./");

	if (dp != NULL)
	{
		while (ep = readdir(dp))
			i++;

		(void)closedir(dp);
	}
	else
		perror("Nao foi possivel abrir a diretoria");

	cout << "Existem " << i << " ficheiros na diretoria atual.\n" << endl;
	return 0;
}

int ContarDiretorias()
{
	return 0;
}

int Sistemaficheiros::Memoria()
{
	return 0;
}

string Sistemaficheiros::DiretoriaMaisElementos()
{
	return string();
}

string Sistemaficheiros::DiretoriaMenosElementos()
{
	return string();
}

string Sistemaficheiros::FicheiroMaior()
{
	return string();
}

string Sistemaficheiros::DiretoriaMaisEspaco()
{
	return string();
}

string Sistemaficheiros::Search(const string& s, int Tipo)
{
	return string();
}

bool Sistemaficheiros::RemoverAll(const string& s, const string& tipo)
{
	return false;
}

void Sistemaficheiros::Escrever_XML(const string& s)
{
}

bool Sistemaficheiros::Ler_XML(const string& s)
{
	return false;
}

bool Sistemaficheiros::MoverFicheiro(const string& Fich, const string& DirNova)
{
	return false;
}

bool Sistemaficheiros::MoverDir(const string& DirOld, const string& DirNova)
{
	return false;
}

string Sistemaficheiros::DataFicheiro(const string& ficheiro)
{
	return string();
}
/*
void Sistemaficheiros::Tree(const string* fich)
{
	return;
}
*/
void Sistemaficheiros::PesquisarAllDiretorias(list<string>& Ires, const string& dir)
{
}

void Sistemaficheiros::PesquisarAllFicheiros(list<string>& Ires, const string& file)
{
}

void Sistemaficheiros::RenomearFicheiros(const string& fich_old, const string& fich_new)
{
}

bool Sistemaficheiros::FicheiroDuplicados()
{
	return false;
}

bool Sistemaficheiros::CopyBatch(const string& padrao, const string& DirOrigem, const string& DirDestino)
{
	return false;
}
