#ifndef CHARACTERISTIQUES
#define CHARACTERISTIQUES

#include <vector>

int nbr_voisins_blanc(Matrice matrice, int x, int y);
int perimeter(Matrice matrice);
int surface(Matrice matr);

std::vector<int> mat_to_vector(const Matrice& matrice);

struct Couple{int i; int j;};

#endif // CHARACTERISTIQUES
