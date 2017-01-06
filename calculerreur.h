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

void calculErreur(std::vector<int>(*f)(const Matrice&),int(*g)(const std::vector<Point>&,const Point&),const std::string& nom,TypeVision t);
void chargerInfoFichiers(std::vector<fichierImage>*img,std::string str);

#endif
