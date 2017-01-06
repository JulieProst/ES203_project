#ifndef GRAPHE
#define GRAPHE

#include<vector>
#include"matrice.h"
#include"readbmp.h"
#include"calculerreur.h"
#include"struct.h"

std::vector<Point> createGraphe( std::vector<int>(*f)(const Matrice&),std::string name);
void saveGraph(const std::vector<Point>& graph,const std::string& name);
void loadGraph(std::vector<Point>*graph,const std::string& name);

#endif
