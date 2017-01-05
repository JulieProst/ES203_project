#ifndef CHARACTERISTIQUES
#define CHARACTERISTIQUES

#include <vector>
#include "matrice.h"

int nbr_voisins_blanc(Matrice matrice, int x, int y);
int perimeter(Matrice matrice);
int surface(Matrice matr);
bool is_external(Matrice mat, unsigned int x, unsigned int y);
bool is_internal(Matrice mat, unsigned int x, unsigned int y);
int nbr_trous(const Matrice& matrice);

std::vector<int> mat_to_vector(const Matrice& matrice);

struct Couple{int i; int j;};

#endif // CHARACTERISTIQUES
