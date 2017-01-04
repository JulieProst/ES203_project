#ifndef MATRICE
#define MATRICE


class Matrice
{
	public :
		Matrice(unsigned int h, unsigned int w);
		Matrice(const Matrice&);
		~Matrice();
		int& operator()(unsigned int i, unsigned int j);
		int& operator()(unsigned int i);
	
	private :
		int * m_data;
		unsigned int m_width,m_height;
};




#endif
