#include "tests.h"

using namespace std;

std::ostream& operator<<(std::ostream& oss, const std::vector<int>& M)
{
	for(unsigned int i=0;i<M.size();i++)
	{
    oss<<M[i];
	oss<<std::string("\n");
	}
	return oss;
}

void test_perimeter(const std::string& filename)
{
    Matrice matrice = readBMP(filename).lettre(1);
    int perimetre;
    perimetre = perimeter(matrice);
    cout << perimetre << endl;
}

void test_mat_to_vector(const std::string& filename)
{
    Matrice matrice = readBMP(filename).lettre(1);
    std::vector<int> caracteres;
    caracteres = mat_to_vector(matrice);
    std::cout << caracteres << std::endl;
}

void test_nbr_trous(const std::string& filename)
{
    Matrice matrice = encadrement_chiffre(readBMP(filename).lettre(3));
    //m2 = encadrement_chiffre(matrice);
    cout << matrice << endl;
    remplissage(matrice);
    cout << matrice << endl;
    int nb_trous = nbr_trous(matrice);
    cout << nb_trous << endl;
}
