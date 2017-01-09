#ifndef CHARACTERISTIQUES
#define CHARACTERISTIQUES

#include <vector>
#include "matrice.h"

int nbr_voisins_blanc(const Matrice& matrice, int x, int y);
int perimeter(const Matrice& matrice);
int surface(const Matrice& matr);
bool is_external(const Matrice& mat, unsigned int x, unsigned int y);
bool is_internal(const Matrice& mat, unsigned int x, unsigned int y);
Matrice encadrement_chiffre(const Matrice& matrice);
void remplissage(const Matrice& matrice);
int nbr_trous(const Matrice& matrice);

std::vector<int> mat_to_vector(const Matrice& matrice);

struct Couple{int i; int j;};

#endif // CHARACTERISTIQUES
