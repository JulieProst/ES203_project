#include <iostream>
#include "Characteristiques.h"
#include "matrice.h"
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
 caracteres[2] : nombre de trous
*/
std::vector<int> mat_to_vector(const Matrice& matrice)
{
    std::vector<int> caracteres;
    int perimetre = perimeter(matrice);
    int surf = surface(matrice);
    Matrice matricebis = encadrement_chiffre(matrice);
    // Calcul du coef de normalisation pour le perimeter et la surface
    int height = matricebis.h(), width = matricebis.w();
    int coef_norm = 10000/(height*width);
    matricebis = remplissage(matricebis);
    int nb_trous = nbr_trous(matricebis);
    caracteres.push_back(coef_norm*perimetre);
    caracteres.push_back(coef_norm*surf);
    caracteres.push_back(nb_trous);
    return caracteres;
}

// Renvoit 1 si le pixel (x,y) est externe, 0 sinon
bool is_external(Matrice mat, unsigned int x, unsigned int y)
{
    int nbr_noir=0;
    Matrice matrice = mat.sous_matrice(x,y,2,2);
    nbr_noir = matrice.somme();
    if(nbr_noir==1){
        return 1;
    }
    else{
        return 0;
    }
}

// Renvoit 1 si le pixel (x,y) est interne, 0 sinon
bool is_internal(Matrice mat,unsigned int x, unsigned int y)
{
    int nbr_noir=0;
    Matrice matrice = mat.sous_matrice(x,y,2,2);
    nbr_noir = matrice.somme();

    if(nbr_noir==3){
        return 1;
    }
    else{
        return 0;
    }
}


// Supprime les lignes et les colonnes entièrement blanches de la matrice 64x64 entrée en argument
Matrice encadrement_chiffre(const Matrice& matrice)
{
    unsigned int nbr_line_deb=0, nbr_line_fin=matrice.h()-1, nbr_col_deb=0, nbr_col_fin=matrice.w()-1;
    // On cherche le nombre de lignes entièrement blanches au dessus du chiffre
    while(somme_line(matrice, nbr_line_deb)==matrice.w()){
        nbr_line_deb++;
    }
    while(somme_line(matrice, nbr_line_fin)==matrice.w()){
        nbr_line_fin--;
    }
    while(somme_col(matrice, nbr_col_deb)==matrice.h()){
        nbr_col_deb++;
    }
    while(somme_col(matrice, nbr_col_fin)==matrice.h()){
        nbr_col_fin--;
    }

    int h = nbr_line_fin - nbr_line_deb;
    int w = nbr_col_fin - nbr_col_deb;
    return matrice.sous_matrice(nbr_line_deb, nbr_col_deb, h, w);
}


// Remplissage des bords de la sous-matrice obtenue par encadrement
Matrice remplissage(const Matrice& matrice)
{
    unsigned int j = 0;
    int k = matrice.w()-1;
    for(unsigned int i=0; i<matrice.h(); i++){
        // Pour remplir en noir les bords gauche de l'image
        while(matrice(i,j)==1 && j<matrice.w()){
            matrice(i,j)=0;
            j++;
        }
        j=0;
        // Pour remplir en noir les bords droit de l'image
        while(matrice(i,k)==1 && k>=0){
            matrice(i,k)=0;
            k--;
        }
        k=matrice.w()-1;
    }
    return matrice;
}

int nbr_trous(const Matrice& matrice)
{
    int nbr_t=0;
    int e=0, i=0;

    for(unsigned int x=0; x<matrice.h()-1; x++){
        for(unsigned int y=0; y<matrice.w()-1; y++){
            if(is_external(matrice, x, y)){
                e++;
            }
            else if(is_internal(matrice,x,y)){
                i++;
            }
        }
    }
    nbr_t = (e-i)/4;
    return(nbr_t);
}
