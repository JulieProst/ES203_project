#ifndef MATRICE
#define MATRICE

#include<iostream>


class Matrice
{
	public :
		Matrice(unsigned int h, unsigned int w);
		Matrice(const Matrice&);
		~Matrice();
		int& operator()(unsigned int i, unsigned int j) const;
		int& operator()(unsigned int i) const;
		unsigned int w() const;
		unsigned int h() const;
		Matrice sous_matrice(unsigned int i, unsigned int j, unsigned int h, unsigned int w) const;
		Matrice lettre(unsigned int i);
		int somme();
		Matrice dilate() const;
		Matrice erode()const ;
		Matrice ouverture()const;
		Matrice fermeture()const;

	private :
		int * m_data;
		unsigned int m_width,m_height;
};


std::ostream& operator<<(std::ostream& oss, const Matrice& M);

unsigned int somme_line(const Matrice& matrice, int i);
unsigned int somme_col(const Matrice& matrice, int j);

#endif
