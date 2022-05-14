#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <filesystem>	//Versão C++17 +	Biblioteca com varias funções que auxiliam o tratamento de operações relacionadas com ficheiros/diretorias e os seus componentes
#include <cstdio>
#include <list>
#include <string>
#include <dirent.h>
#include <direct.h>		//para obter a diretoria atual do programa (função _getcwd())
#include <limits.h>
#include <locale.h>
#include <sys/stat.h>
#include <time.h>

using namespace std;
namespace fs = std::filesystem;