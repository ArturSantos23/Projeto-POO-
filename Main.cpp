#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <filesystem>	//Vers�o C++17 +	Biblioteca com varias fun��es que auxiliam o tratamento de opera��es relacionadas com ficheiros/diretorias e os seus componentes
#include <cstdio>
#include <list>
#include <string>
#include <dirent.h>
#include <direct.h>		//para obter a diretoria atual do programa (fun��o _getcwd())
#include <limits.h>
#include <locale.h>
#include <sys/stat.h>
#include <time.h>

using namespace std;
namespace fs = std::filesystem;