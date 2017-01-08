#include <iostream>
#include<time.h>
#include<stdlib.h>
#include "calculerreur.h"
#include "Characteristiques.h"
#include "tests.h"
#include "kppv.h"

using namespace std;

int main()
{
    string filename = "appr/appr_7.bmp";
    cout << "Result test perimeter" << endl;
    test_perimeter(filename);
//    cout << "Result test mat_to_vector" << endl;
//    test_mat_to_vector(filename);

// is_external et is_internal fonctionnent
/*
    cout << "Result test nbr_trous" << endl;
    Matrice mat(3,3);
    mat(1,1)=1;
    mat(0,0)=0;
    mat(1,0)=0;
    mat(0,1)=1;
    for(int i=0; i<3; i++){mat(2,i)=0;}
    mat(0,2)=0;
    mat(1,2)=0;
    cout<< "is_external? " << is_external(mat, 0,0) << endl;
    cout<< "is_internal? " << is_internal(mat, 0,0) << endl;
*/
    cout << "Result test nbr_trous" << endl;
    test_nbr_trous(filename);


//	srand (time(NULL));
//	calculErreur(mat_to_vector,kppv,"walla",WATCH);
	return 0;
}
