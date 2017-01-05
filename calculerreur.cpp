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

static std::string analyseFichier(int(*f)(const Matrice&),const fichierImage& file)
{
	Matrice M(readBMP(file.nom));
	int detected[11]={0};
	for(int i=0;i<file.nb;i++)		
	{
		int val=f(M.lettre(i));		
		if(val==-1)
			detected[10]++;
		else
			detected[val]++;
	}

	std::cout<<"\tErreur de "<<100-detected[file.value]*100/file.nb<<"%"<<std::endl;

	std::string str=inString(file.value);
	for(int i=0;i<11;i++) {
		str+=",";
		str+=inString(detected[i]);
	}
	
	return str+"\n";
}

void calculErreur(int(*f)(const Matrice&),const std::string& nom)
{
	std::vector<fichierImage>img;
	chargerInfoFichiers(&img);

	std::ofstream file;
	file.open(nom+"/resultats.csv");
	file<<"Nombre étudié,0,1,2,3,4,5,6,7,8,9,fauxpositifs\n";

	for(unsigned int i=0;i<img.size();i++)
	{
		std::cout<<"Analyse de "<<img[i].nom<<std::endl;
		file << analyseFichier(f,img[i]);
	}
	file.close();
}

