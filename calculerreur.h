#ifndef CALCULERREUR
#define CALCULERREUR

#include "matrice.h"
#include <string>
#include"readbmp.h"

struct fichierImage
{
	std::string nom;
	int nb,value;
};


int methodeBidon(const Matrice&);
void calculErreur(int(*f)(const Matrice&),const std::string& name);

#endif
