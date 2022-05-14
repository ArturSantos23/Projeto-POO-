#include "libs.h"
#include "SistemaFicheiros.h"
#include "Menus.h"

int main()
{
	setlocale(LC_ALL, "Portuguese");
	SistemaFicheiros* F = new SistemaFicheiros();
	Menus::Select(F);

	delete F;
	return 0;
}