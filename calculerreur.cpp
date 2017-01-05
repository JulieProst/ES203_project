#include"calculerreur.h"
#include<string>
#include<stdlib.h>
#include<sstream>
#include<time.h>
#include<fstream>
#include"graphe.h"

std::string inString(int n)
{
	std::stringstream out;
	out << n;
	return out.str();	
}

void chargerInfoFichiers(std::vector<fichierImage>*img,std::string str)
{
	fichierImage info;
	int rec[]={465,465,462,464,429,431,463,464,456,446};
	int appr[]={489,452,452,453,431,409,452,449,447,422};
	int *a;

	if(str=="rec")
		a=rec;
	else
		a=appr;

	info.nom=str+"/"+str+"_0.bmp"; info.nb=a[0]; info.value=0; img->push_back(info);
	info.nom=str+"/"+str+"_1.bmp"; info.nb=a[1]; info.value=1; img->push_back(info);
	info.nom=str+"/"+str+"_2.bmp"; info.nb=a[2]; info.value=2; img->push_back(info);
	info.nom=str+"/"+str+"_3.bmp"; info.nb=a[3]; info.value=3; img->push_back(info);
	info.nom=str+"/"+str+"_4.bmp"; info.nb=a[4]; info.value=4; img->push_back(info);
	info.nom=str+"/"+str+"_5.bmp"; info.nb=a[5]; info.value=5; img->push_back(info);
	info.nom=str+"/"+str+"_6.bmp"; info.nb=a[6]; info.value=6; img->push_back(info);
	info.nom=str+"/"+str+"_7.bmp"; info.nb=a[7]; info.value=7; img->push_back(info);
	info.nom=str+"/"+str+"_8.bmp"; info.nb=a[8]; info.value=8; img->push_back(info);
	info.nom=str+"/"+str+"_9.bmp"; info.nb=a[9]; info.value=9; img->push_back(info);
}

static std::string analyseFichier(std::vector<int>(*f)(const Matrice&),int(*g)(const std::vector<Point>&,const Point&),const std::vector<Point> & graph,const fichierImage& file,std::vector<Matrice>*ensembleImage)
{
	Matrice M(readBMP(file.nom));
	Point a;
	a.etiquette=-1;
	int detected[11]={0};
	for(int i=0;i<file.nb;i++)		
	{
		a.coord=f(M.lettre(i));
		int val=g(graph,a);		
		if(val==-1){
			detected[10]++;
			ensembleImage[10].push_back(M.lettre(i));
		}
		else {
			detected[val]++;
			ensembleImage[val].push_back(M.lettre(i));
		}
	}

	std::cout<<"\tErreur de "<<100-detected[file.value]*100/file.nb<<"%"<<std::endl;

	std::string str=inString(file.value);
	for(int i=0;i<11;i++) {
		str+=",";
		str+=inString(detected[i]);
	}
	
	return str+"\n";
}

static void createImages(std::string nom,std::vector<Matrice>* ensembleImage)
{
	for(unsigned int i=0;i<11;i++) {
		std::ofstream file;
		file.open((nom+"/chiffre"+inString(i)+".pbm").c_str());
		unsigned int h;

		h=ensembleImage[i].size()/20+1;
		file<<"P1\n"<<20*64<<" "<<h*64<<std::endl;

		for(unsigned int j=0;j<h;j++) {
			for(unsigned int ligne=0;ligne<64;ligne++) {
				for(unsigned int a=0;a<20;a++) {
					if(j==h-1 && j*20+a>=ensembleImage[i].size())
						for(unsigned int colonne=0;colonne<64;colonne++) 
							file<<0<<" ";
					else 
						for(unsigned int colonne=0;colonne<64;colonne++) 
							file<<1-ensembleImage[i][j*20+a](ligne,colonne)<<" ";
				}
				file<<std::endl;
			}
		}


		file.close();
	}
}

void calculErreur(std::vector<int>(*f)(const Matrice&),int(*g)(const std::vector<Point>&,const Point&),const std::string& nom)
{
	std::vector<fichierImage>img;
	chargerInfoFichiers(&img,"rec");

	std::vector<Matrice> ensembleImage[11];

	std::vector<Point> graph(createGraphe(f));


	std::ofstream file;
	file.open((nom+"/resultats.csv").c_str());
	file<<"Nombre étudié,0,1,2,3,4,5,6,7,8,9,illisibles\n";

	for(unsigned int i=0;i<img.size();i++)
	{
		std::cout<<"Analyse de "<<img[i].nom<<std::endl;
		file << analyseFichier(f,g,graph,img[i],ensembleImage);
	}
	std::cout<<"Ecriture des donnees."<<std::endl;
	createImages(nom,ensembleImage);
	file.close();
}

