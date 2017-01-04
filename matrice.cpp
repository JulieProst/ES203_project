#include"matrice.h"
#include<stdexcept>

Matrice::Matrice(unsigned int h, unsigned int w)
{
	m_data=new int[h*w];
	for(unsigned int i=0;i<h*w;i++)
		m_data[i]=0;
	m_height=h;
	m_width=w;
}

Matrice::~Matrice()
{
	delete m_data;
}

int& Matrice::operator()(unsigned int i, unsigned int j)
{
	if(i>= m_height || j >= m_width)
		throw std::runtime_error( "Indices out of range." );
	return m_data[i*m_width+j];
}

int& Matrice::operator()(unsigned int i)
{
	if(i>= m_height*m_width)
		throw std::runtime_error( "Indices out of range." );
	return m_data[i];
}

