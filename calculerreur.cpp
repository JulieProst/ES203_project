#include"calculerreur.h"
#include <vector>
#include<string>
#include<stdlib.h>
#include<sstream>
#include<time.h>
#include<fstream>

int methodeBidon(const Matrice &)
{
	return (rand()%11)-1;
}


std::string inString(int n)
{
	std::stringstream out;
	out << n;
	return out.str();	
}

static void chargerInfoFichiers(std::vector<fichierImage>*img)
{
	fichierImage info;
	info.nom="rec/rec_0.bmp"; info.nb=465; info.value=0; img->push_back(info);
	info.nom="rec/rec_1.bmp"; info.nb=465; info.value=1; img->push_back(info);
	info.nom="rec/rec_2.bmp"; info.nb=462; info.value=2; img->push_back(info);
	info.nom="rec/rec_3.bmp"; info.nb=464; info.value=3; img->push_back(info);
	info.nom="rec/rec_4.bmp"; info.nb=429; info.value=4; img->push_back(info);
	info.nom="rec/rec_5.bmp"; info.nb=431; info.value=5; img->push_back(info);
	info.nom="rec/rec_6.bmp"; info.nb=463; info.value=6; img->push_back(info);
	info.nom="rec/rec_7.bmp"; info.nb=464; info.value=7; img->push_back(info);
	info.nom="rec/rec_8.bmp"; info.nb=456; info.value=8; img->push_back(info);
	info.nom="rec/rec_9.bmp"; info.nb=446; info.value=9; img->push_back(info);
}

static std::string analyseFichier(int(*f)(const Matrice&),const fichierImage& file,std::vector<Matrice>*ensembleImage)
{
	Matrice M(readBMP(file.nom));
	int detected[11]={0};
	for(int i=0;i<file.nb;i++)		
	{
		int val=f(M.lettre(i));		
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

void calculErreur(int(*f)(const Matrice&),const std::string& nom)
{
	std::vector<fichierImage>img;
	chargerInfoFichiers(&img);

	std::vector<Matrice> ensembleImage[11];

	std::ofstream file;
	file.open((nom+"/resultats.csv").c_str());
	file<<"Nombre étudié,0,1,2,3,4,5,6,7,8,9,illisibles\n";

	for(unsigned int i=0;i<img.size();i++)
	{
		std::cout<<"Analyse de "<<img[i].nom<<std::endl;
		file << analyseFichier(f,img[i],ensembleImage);
	}
	std::cout<<"Ecriture des donnees."<<std::endl;
	createImages(nom,ensembleImage);
	file.close();
}

