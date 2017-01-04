#include <iostream>

#include "matrice.h"

using namespace std;

int perimeter(Matrice matrice)
{
    int perimetre = 1;
    int i=0, j=0;

    // On cherche le premier pixel noir
    int I_in = 0;
    int J_in = 0;
    while (matrice(I_in,J_in) = 1)
    {
        if J_in < 62
        {
            J_in++;
        }
        else
        {
            J_in = 0;
            I_in++;
        }

        if I_in >= 62
        {
            cout << "Error : l'image est entièrement blanche" << endl;
            return 0;
        }
    }

    // On cherche le premier voisin
    if (matrice(I_in-1,J_in) = 1)
    {
        perimetre++;
        i = I_in-1;
        j = J_in+1;
    }

    else if (matrice(I_in-1,J_in) = 1 && matrice(I_in))
    {

    }

    // On lance la boucle qui calcule aussi le perimètre
    while (i!=I_in && j!=J_in  )
        {
            if (matrice(i+1,j) = 1
                {
                    perimetre++;
                }
            if (matrice())
        }


    return perimetre;
}
