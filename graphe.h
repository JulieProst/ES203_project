#ifndef GRAPHE
#define GRAPHE

#include<vector>
#include"matrice.h"
#include"readbmp.h"
#include"calculerreur.h"
#include"struct.h"

std::vector<Point> createGraphe( std::vector<int>(*f)(const Matrice&));

#endif
