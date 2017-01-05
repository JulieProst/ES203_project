#include <iostream>
#include "matrice.h"
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
    for(int k = 0; k<Index.size(); k++){
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

