#include "graphe.h"
#include<iostream>
#include<fstream>

std::vector<Point> createGraphe( std::vector<int>(*f)(const Matrice&),std::string name)
{
	std::vector<Point> graph;
	std::vector<fichierImage>img;

	chargerInfoFichiers(&img,"appr");

	for(unsigned int i=0;i<img.size();i++) {
		std::cout<<"Apprentissage de "<<img[i].nom<<std::endl;
		for(int j=0;j<img[i].nb;j++){
			Point a;	
			a.coord=f(readBMP(img[i].nom).lettre(j));
			a.etiquette=img[i].value;
			graph.push_back(a);
		}
	}
	
	saveGraph(graph,name+"/apprentissage.txt");
	return graph;
}

void saveGraph(const std::vector<Point>& graph,const std::string& name)
{
	std::ofstream file(name);
	file<<graph.size()<<" "<<graph[0].coord.size()<<std::endl;
	for(unsigned int i=0;i<graph.size();i++)
	{
		file<<graph[i].etiquette;
		for(unsigned int j=0;j<graph[i].coord.size();j++)
			file<<" "<<graph[i].coord[j];
		file<<std::endl;
	}
}

void loadGraph(std::vector<Point>*graph,const std::string& name)
{
	std::fstream file(name+"/apprentissage.txt",std::ios_base::in);
	int n,p;
	std::vector<Point> point;

	file>>n>>p;

	for(int i=0;i<n;i++){
		Point pt;
		pt.etiquette=-1;
		file>>pt.etiquette;
		for(int j=0;j<p;j++) {
			int k;
			file>>k;
			pt.coord.push_back(k);
		}

		graph->push_back(pt);
	}
}
