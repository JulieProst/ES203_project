#include <iostream>
#include "Characteristiques.h"
#include <vector>

using namespace std;

// Calcule le nombre de voisins blancs de l'élément (x,y) de la matrice
// Ne fonctionne pas pour les éléments du bord
int nbr_voisins_blanc(Matrice matrice, int x, int y)
{
    int nbr_voisins = 0;
    if (matrice(x-1,y)==1){nbr_voisins++;}
    if (matrice(x,y-1)==1){nbr_voisins++;}
    if (matrice(x+1,y)==1){nbr_voisins++;}
    if (matrice(x,y+1)==1){nbr_voisins++;}
    return nbr_voisins;
}

int perimeter(Matrice matrice)
{
    int perimetre = 0;
    int nbr_vois = 0;
    vector<Couple> Index;

    // On recense les coordonnees de tous les pixels noirs
    for(int i = 0; i<64; i++){
        for(int j = 0; j<64; j++){
            if(matrice(i,j)==0){
                Couple couple;
                couple.i=i;
                couple.j=j;
                Index.push_back(couple);
            }
        }
    }

    // On compte les voisins blancs de chaque pixel noir
    for(unsigned int k = 0; k<Index.size(); k++){
        int i = Index[k].i;
        int j = Index[k].j;
        nbr_vois = nbr_voisins_blanc(matrice,i,j);
        perimetre+=nbr_vois;
    }

    return perimetre;
}

int surface(Matrice matr){
    int surf=0;
     for (int i=0; i<62; i++){
        for (int j=0; j<62; j++){
                if (matr(i,j)==0){
                    surf ++;
                }
    }
    }
    return surf;
}

/* Donne les caractéristiques d'une matrice 64x64
 caracteres[0] : perimeter
 caracteres[1] : surface
*/
std::vector<int> mat_to_vector(const Matrice& matrice)
{
    std::vector<int> caracteres;
    caracteres.push_back(perimeter(matrice));
    caracteres.push_back(surface(matrice));
    return caracteres;
}

// Renvoit 1 si le pixel (x,y) est externe, 0 sinon
bool is_external(Matrice mat, unsigned int x, unsigned int y)
{
    int nbr_noir=0;
    Matrice matrice = mat.sous_matrice(x,y,2,2);
    nbr_noir = matrice.somme();
    if(nbr_noir==3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Renvoit 1 si le pixel (x,y) est interne, 0 sinon
bool is_internal(Matrice mat,unsigned int x, unsigned int y)
{
    int nbr_noir=0;
    Matrice matrice = mat.sous_matrice(x,y,2,2);
    nbr_noir = matrice.somme();

    if(nbr_noir==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int nbr_trous(const Matrice& matrice)
{
    int nbr_t=0;
    int e=0, i=0;

    for(unsigned int x=0; x<63; x++)
    {
        for(unsigned int y=0; y<63; y++)
        {
            if(is_external(matrice, x, y))
            {
                e++;
            }
            else if(is_internal(matrice,x,y))
            {
                i++;
            }
        }
    }

    nbr_t = (e-i)/4;
    return(nbr_t);
}
