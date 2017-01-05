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
		Matrice sous_matrice(unsigned int i, unsigned int j, unsigned int h, unsigned int w);
		Matrice lettre(unsigned int i);
		int somme();

	private :
		int * m_data;
		unsigned int m_width,m_height;
};

std::ostream& operator<<(std::ostream& oss, const Matrice& M);

#endif
