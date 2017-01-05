#include "graphe.h"
#include<iostream>

std::vector<Point> createGraphe( std::vector<int>(*f)(const Matrice&))
{
	std::vector<Point> graph;
	std::vector<fichierImage>img;

	chargerInfoFichiers(&img,"appr");

	for(unsigned int i=0;i<img.size();i++) {
		std::cout<<"Apprentissage de "<<img[i].nom<<std::endl;
		for(int j=0;j<img[i].nb;j++){
			Point a;	
			a.coord=f(readBMP(img[i].nom).lettre(i));
			a.etiquette=img[i].value;
			graph.push_back(a);
		}
	}

	return graph;
}

