#include "Diretoria.h"

Diretoria::Diretoria(tm* _data, string _caminho, string _nome)
	: ObjetoGeral(_data, _caminho, _nome)
{
	//ctor
}

Diretoria::~Diretoria()
{
	for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
		delete* it;

	for (list<Ficheiro*>::iterator it = LFich.begin(); it != LFich.end(); ++it)
		delete* it;
}

void Diretoria::ContarFicheiros(int* NumFich)
{
	for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
		(*it)->ContarFicheiros(NumFich);

	for (list<Ficheiro*>::iterator it2 = LFich.begin(); it2 != LFich.end(); ++it2)
		*NumFich = *NumFich + 1;
}

void Diretoria::ContarDiretorias(int* NumDir)
{
	for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
	{
		*NumDir = *NumDir + 1;
		(*it)->ContarDiretorias(NumDir);
	}
}

void Diretoria::Memoria(int* MemoriaTotal)
{
	*MemoriaTotal = *MemoriaTotal + sizeof(Diretoria) + sizeof(Ficheiro) * this->GetNumFich();
	for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
		(*it)->Memoria(MemoriaTotal);
}

void Diretoria::DirMaisElementos(int* NumElementos, string* DirPath, string* DirName)
{
	if (*NumElementos < this->GetNumElem())
	{
		*NumElementos = this->GetNumElem();
		*DirPath = this->GetPath();
		*DirName = this->GetNome();
	}

	for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
	{
		*NumElementos = *NumElementos + this->GetNumElem();
		(*it)->DirMaisElementos(NumElementos, DirPath, DirName);
	}
}

void Diretoria::DirMaisElementosRoot(int* NumElementos, string* DirPath, string* DirName)
{
	for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
	{
		(*it)->DirMaisElementos(NumElementos, DirPath, DirName);
	}
}

void Diretoria::DirMenosElementos(int* NumElementos, string* DirPath, string* DirName)
{
	for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
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

void Diretoria::DirMenosElementosRoot(int* NumElementos, string* DirPath, string* DirName)
{
	for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
	{
		(*it)->DirMenosElementos(NumElementos, DirPath, DirName);
	}
}

void Diretoria::FichMaior(int* Tamanho, string* FichPath, string* NomeFich)
{
	for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
		(*it)->FichMaior(Tamanho, FichPath, NomeFich);

	for (list<Ficheiro*>::iterator it2 = LFich.begin(); it2 != LFich.end(); ++it2)
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
	for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
		Tamanho_Total = (*it)->GetTamanhoDir();

	for (list<Ficheiro*>::iterator it2 = LFich.begin(); it2 != LFich.end(); ++it2)
		Tamanho_Total = Tamanho_Total + (*it2)->GetTamanho();

	return Tamanho_Total;
}

void Diretoria::DiretoriaMaior(int* Tamanho, string* DirPath, string* NomeDir)
{
	if (*Tamanho < this->GetTamanhoDir())
	{
		*Tamanho = this->GetTamanhoDir();
		*DirPath = this->GetPath();
		*NomeDir = this->GetNome();
	}

	for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
	{
		(*it)->DiretoriaMaior(Tamanho, DirPath, NomeDir);
	}
}

void Diretoria::DiretoriaMaiorRoot(int* Tamanho, string* DirPath, string* NomeDir)
{
	for (list<Ficheiro*>::iterator it = LFich.begin(); it != LFich.end(); ++it)
		(*it)->GetTamanho();

	for (list<Diretoria*>::iterator it2 = LDir.begin(); it2 != LDir.end(); ++it2)
	{
		if ((*it2)->GetTamanhoDir() > *Tamanho)
		{
			*Tamanho = (*it2)->GetTamanhoDir();
			*DirPath = (*it2)->GetPath();
			*NomeDir = (*it2)->GetNome();
		}
	}
}

void Diretoria::SearchFicheiros(const string& FileName, string& Caminho)
{
	for (list<Ficheiro*>::iterator it = LFich.begin(); it != LFich.end(); ++it)
	{
		if ((*it)->GetNome().compare(FileName) == 0)
		{
			Caminho = (*it)->GetPath();
			return;
		}
	}
	for (list<Diretoria*>::iterator it2 = LDir.begin(); it2 != LDir.end(); ++it2)
		(*it2)->SearchFicheiros(FileName, Caminho);
}

void Diretoria::Search(const string& DirName, string& Caminho)
{
	if (this->GetNome().compare(DirName) == 0)
	{
		Caminho = this->GetPath();
		return;
	}
	for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
		(*it)->Search(DirName, Caminho);
}

bool Diretoria::RemoveDiretoria(const string& DirName)
{
	if (fs::remove_all(DirName.c_str())) //Apaga todo conteúdo da diretoria e de todas as suas subdiretorias, recursivamente, e no final apaga-se a si mesmo(diretoria "mãe")
	{
		if (LFich.size() != 0)
			this->LFich.erase(LFich.begin(), LFich.end());
		if (LDir.size() != 0)
			this->LDir.erase(LDir.begin(), LDir.end());
		delete this;

		cout << "Diretoria " << DirName << " eliminada com sucesso!" << endl;
		return true;
	}
	else
	{
		cout << "Nao foi possivel eliminar a diretoria com o nome " << DirName << endl;
		return false;
	}
}

bool Diretoria::RemoveFicheiros(const string& Path)
{
	if (fs::exists(Path.c_str()) && fs::is_directory(Path.c_str()))
	{
		fs::directory_iterator end;
		for (fs::directory_iterator it(Path.c_str()); it != end; ++it)
		{
			if (fs::is_regular_file(it->status()) && (it->path().extension() == ".txt") || (it->path().extension() == ".pdf") || (it->path().extension() == ".docx"))      //adicionar com "ou" as extensões dos ficheiros a eliminar
			{
				for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
					(*it)->RemoveFicheiros(Path);

				if (this->LFich.size() != 0)
					this->LFich.erase(LFich.begin(), LFich.end());

				fs::remove(it->path());
			}
		}
		return true;
	}
	else
	{
		cout << endl << "[ERRO!!]: Nao foi possivel eliminar os ficheiros da diretoria com o nome " << Path << endl;
		return false;
	}
}

void Diretoria::EscreverXML(ofstream& File, int Espacos)
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
		for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
			(*it)->EscreverXML(File, Espacos + 1);
		FechaElementoXML(File, Espacos + 1, "LDir");
	}

	if (this->GetNumFich() != 0)
	{
		EscreveElementoXML(File, Espacos + 1, "LFich");
		File << "\n";
		for (list<Ficheiro*>::iterator it = LFich.begin(); it != LFich.end(); ++it)
			(*it)->EscreverXML(File, Espacos + 2);
		FechaElementoXML(File, Espacos + 1, "LFich");
	}

	FechaElementoXML(File, Espacos, "Diretoria");
}

bool Diretoria::MoveFicheiro(const string& Fich, string DirAntiga, string DirNova)
{
	for (int i = 0; i < DirAntiga.size(); i++)
	{
		if (DirAntiga[i] == '\\')
			DirAntiga[i] = '/';
	}

	for (int i = 0; i < DirNova.size(); i++)
	{
		if (DirNova[i] == '\\')
			DirNova[i] = '/';
	}

	if (DirAntiga[DirAntiga.size() - 1] != '/')
		DirAntiga.push_back('/');

	DirAntiga = DirAntiga + Fich;

	if (DirNova[DirNova.size() - 1] != '/')
		DirNova.push_back('/');

	DirNova = DirNova + Fich;
	ifstream DirAntigaFich(DirAntiga.c_str(), ios::binary);

	if (DirAntigaFich)
	{
		ifstream iDirNova(DirNova.c_str());
		if (iDirNova)
		{
			cout << Fich << " O ficheiro que esta a mover ja existe na diretoria nova." << endl << endl << "A sair......." << endl;
			system("pause");
			iDirNova.close();
			return false;
		}
		else
		{
			iDirNova.close();
			ofstream DirNovaFich(DirNova.c_str(), ios::binary);
			string line;
			while (getline(DirAntigaFich, line))
			{
				DirNovaFich << line << endl;;
			}
			DirNovaFich.flush();
			DirNovaFich.close();
			DirAntigaFich.close();
			int old_file = remove(DirAntiga.c_str());
			if (old_file == 0)
			{
				return true;
			}
			else
			{
				cout << "[ERRO!!]: Nao foi possivel mover o ficheiro. Tente novamente por favor." << endl;
				system("pause");
				return false;
			}
		}
		DirAntigaFich.close();
	}
	else
	{
		cout << "[ERRO!!]" << endl;
		cout << "Nao foi possivel localizar o ficheiro: " << DirAntiga << endl;
		cout << "Por favor insira uma diretoria valida." << endl;
		return false;
	}
}

bool Diretoria::MoverDirectoria(const string& DirOld, const string& DirNew)
{
	const auto copyOptions = fs::copy_options::overwrite_existing | fs::copy_options::recursive;   //opções adicionais que controlam o comportamento da funçao copy()   
							 //overwrite_existing -> Substitui o arquivo existente caso o mesmo exista na diretoria destino
							//recursive -> Copia recursivamente sub-diretorias e o seu conteudo
	if (rename(DirOld.c_str(), DirNew.c_str()))     //Atualiza a diretoria antiga para a diretoria nova
	{
		fs::copy(DirOld.c_str(), DirNew.c_str(), copyOptions);      //Copia todo o conteúdo presente na diretoria antiga para a diretoria nova, incluindo sub-diretorias (recursivamente)
		fs::remove_all(DirOld.c_str());                             //Elimina todo o conteúdo presente na diretoria antiga, incluindo sub-diretorias (recursivamente)
	}
	else
	{
		cout << "[ERRO!!]" << endl;
		cout << "Nao foi possivel localizar a diretoria: " << DirOld << endl;
		cout << "Por favor insira uma diretoria valida." << endl;
		return false;
	}
}

tm* Diretoria::DataFicheiro(const string& NomeFich)
{
	for (list<Ficheiro*>::iterator it = LFich.begin(); it != LFich.end(); ++it)
	{
		if ((*it)->GetNome().compare(NomeFich) == 0)
			return ((*it)->GetData(NomeFich));
	}
	for (list<Diretoria*>::iterator it2 = LDir.begin(); it2 != LDir.end(); ++it2)
		(*it2)->DataFicheiro(NomeFich);

	return NULL;
}

void Diretoria::PesquisarAllDiretorias(list<string>& LPath, const string& NomeDir)
{
	if (this->GetNome().compare(NomeDir) == 0)
	{
		LPath.push_back(this->GetPath());
	}
	for (list<Diretoria*>::iterator it2 = LDir.begin(); it2 != LDir.end(); ++it2)
		(*it2)->PesquisarAllDiretorias(LPath, NomeDir);
}

void Diretoria::PesquisarAllDiretoriasRoot(list<string>& LPath, const string& NomeDir)
{
	for (list<Diretoria*>::iterator it2 = LDir.begin(); it2 != LDir.end(); ++it2)
		(*it2)->PesquisarAllDiretorias(LPath, NomeDir);
}

void Diretoria::PesquisarAllFicheiros(list<string>& LPath, const string& NomeFicheiro)
{
	for (list<Ficheiro*>::iterator it = LFich.begin(); it != LFich.end(); ++it)
	{
		if ((*it)->GetNome().compare(NomeFicheiro) == 0)
			LPath.push_back((*it)->GetPath());
	}
	for (list<Diretoria*>::iterator it2 = LDir.begin(); it2 != LDir.end(); ++it2)
		(*it2)->PesquisarAllFicheiros(LPath, NomeFicheiro);
}

void Diretoria::RenomearFicheiros(const string& NFich, const string& NNovo)
{
	for (list<Ficheiro*>::iterator it = LFich.begin(); it != LFich.end(); ++it)
	{
		if ((*it)->GetNome().compare(NFich) == 0)
			(*it)->Renomear(NNovo);
	}
	for (list<Diretoria*>::iterator it2 = LDir.begin(); it2 != LDir.end(); ++it2)
		(*it2)->RenomearFicheiros(NFich, NNovo);
}

void Diretoria::RenomearFicheirosRoot(const string& NFich, const string& NNovo)
{
	for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
		(*it)->RenomearFicheiros(NFich, NNovo);
}

bool Diretoria::VerificaNomes(list<string>& LNomes, string NomeVerificar)
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

bool Diretoria::FicheirosDuplicados(list<string>& LNomes)
{
	for (list<Diretoria*>::iterator it = LDir.begin(); it != LDir.end(); ++it)
	{
		int Aux = (*it)->FicheirosDuplicados(LNomes);
		if (Aux)
			return true;
	}

	for (list<Ficheiro*>::iterator it2 = LFich.begin(); it2 != LFich.end(); ++it2)
	{
		if (VerificaNomes(LNomes, (*it2)->GetNome()))
			return true;
		LNomes.push_back((*it2)->GetNome());
	}
}

bool Diretoria::CopyBatch(const string& padrao, const string& DirOrigem, const string& DirDestino)
{
	const auto copyOptions = fs::copy_options::skip_existing | fs::copy_options::recursive;   //opções adicionais que controlam o comportamento da funçao copy()   
							 //skip_existing -> Ignora o arquivo caso o mesmo exista na diretoria destino (com o mesmo nome)
							//recursive -> Copia recursivamente sub-diretorias e o seu conteudo
	if (rename(DirOrigem.c_str(), DirDestino.c_str()))     //Atualiza a diretoria antiga para a diretoria nova
	{
		fs::copy(DirOrigem.c_str(), DirDestino.c_str(), copyOptions);      //Copia todo o conteúdo presente na diretoria antiga para a diretoria nova, incluindo sub-diretorias (recursivamente)
		return true;
	}
	else
	{
		cout << "[ERRO!!]" << endl;
		cout << "Nao foi possivel localizar a diretoria: " << DirOrigem << endl;
		cout << "Por favor insira uma diretoria valida." << endl;
		return false;
	}
	return true;
}