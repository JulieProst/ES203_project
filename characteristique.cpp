#include "characteristique.h"


/*int perimetre(Matrice mat){
    int i=0;
    if (mat(i,j) ==0) {
        i++;
    }
    int pos_in=i;


        }
*/

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
