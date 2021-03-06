#include"matrice.h"
#include<string>
#include<stdexcept>

Matrice::Matrice(unsigned int h, unsigned int w)
{
	m_data=new int[h*w];
	for(unsigned int i=0;i<h*w;i++)
		m_data[i]=0;
	m_height=h;
	m_width=w;
}

Matrice::Matrice(const Matrice& m)
{
	m_width=m.m_width;
	m_height=m.m_height;
	m_data=new int[m_width*m_height];
	for(unsigned int i=0;i<m_width*m_height;i++)
		m_data[i]=m.m_data[i];
}

Matrice::~Matrice()
{
	delete m_data;
}

int& Matrice::operator()(unsigned int i, unsigned int j) const
{
	if(i>= m_height || j >= m_width)
		throw std::runtime_error( "Indices out of range. Operator()(i,j)" );
	return m_data[i*m_width+j];
}

int& Matrice::operator()(unsigned int i) const
{
	if(i>= m_height*m_width)
		throw std::runtime_error( "Indices out of range. Operator()(i)" );
	return m_data[i];
}

unsigned int Matrice::w() const
{
	return m_width;
}

unsigned int Matrice::h() const
{
	return m_height;
}

std::ostream& operator<<(std::ostream& oss, const Matrice& M)
{
	for(unsigned int i=0;i<M.h();i++)
	{
	oss<<std::string("|");
	for(unsigned int j=0;j<M.w();j++)
		{
		oss<<M(i,j);
		if(j!=M.w()-1)
			oss<<std::string(" ");
		}
	oss<<std::string("|\n");
	}
	return oss;
}

Matrice Matrice::sous_matrice(unsigned int i, unsigned int j, unsigned int h, unsigned int w) const
{
	if(i+h> m_height || j+w > m_width)
		throw std::runtime_error( "Indices out of range. sous_matrice" );
	Matrice mat(h,w);

	for(unsigned int a=0;a<h;a++)
		for(unsigned int b=0;b<w;b++)
			mat(a,b)=(*this)(i+a,j+b);
	return mat;
}

Matrice Matrice::lettre(unsigned int n)
{
	int i,j;
	i=n/(w()/64);
	j=n%(w()/64);
	return sous_matrice(i*64,j*64,64,64);
}

int Matrice::somme()
{
	int sum = 0;
	for(unsigned int i=0; i<m_width*m_height; i++)
		sum+=m_data[i];
	return sum;
}

unsigned int somme_line(const Matrice& matrice, int i)
{
    unsigned int sum = 0;
    for(unsigned int k=0; k<matrice.w(); k++)
    {
        sum+=matrice(i,k);
    }
    return sum;
}

unsigned int somme_col(const Matrice& matrice, int j)
{
    unsigned int sum = 0;
    for(unsigned int k=0; k<matrice.h(); k++)
    {
        sum+=matrice(k,j);
    }
    return sum;
}

Matrice  Matrice::dilate() const
{
	Matrice m(*this);
	for(unsigned int i=0;i<m_height;i++) 
		for(unsigned int j=0;j<m_width;j++)
			if(m_data[i*m_width+j]==0){
				if(i>0)
					m(i-1,j)=0;
				if(j>0)
					m(i,j-1)=0;
				if(i>0 && j>0)
					m(i-1,j-1)=0;
				if(i>0 && j<m_width-1)
					m(i-1,j+1)=0;
				if(j<m_width-1)
					m(i,j+1)=0;
				if(j<m_width-1 && i<m_height-1)
					m(i+1,j+1)=0;
				if(i<m_height-1)
					m(i+1,j)=0;
				if(i<m_height-1 && j>0)
					m(i+1,j-1)=0;
	}
	return m;
}

Matrice Matrice::erode() const
{
	Matrice a(*this);
	for(unsigned int i=1;i<m_height-1;i++)
		for(unsigned int j=1;j<m_width-1;j++) 
		if(m_data[i*m_width+j]==0){
			if(m_data[(i-1)*m_width+j-1] ||
			m_data[(i-1)*m_width+j] ||
			m_data[(i-1)*m_width+j+1] ||
			m_data[i*m_width+j+1] ||
			m_data[(i+1)*m_width +j+1] ||
			m_data[(i+1)*m_width+j] ||
			m_data[(i+1)*m_width+j-1] ||
			m_data[i*m_width+j-1])
				a(i,j)=1;
	}
	return a;
}

Matrice Matrice::ouverture() const
{
	return	erode().dilate();
}

Matrice  Matrice::fermeture() const
{
	return dilate().erode();
}

