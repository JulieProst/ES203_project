#ifndef CALCULERREUR
#define CALCULERREUR

#include "matrice.h"
#include <string>
#include <vector>
#include"readbmp.h"
#include"struct.h"

struct fichierImage
{
	std::string nom;
	int nb,value;
};

void calculErreur(int(*f)(const std::vector<Point>,const Matrice&),const std::string& nom);
void chargerInfoFichiers(std::vector<fichierImage>*img,std::string str);

#endif
