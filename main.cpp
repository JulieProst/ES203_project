#include <iostream>
#include<time.h>
#include<stdlib.h>
#include "calculerreur.h"
#include "Characteristiques.h"
#include "tests.h"

using namespace std;

int main()
{
    string filename = "appr/appr_1.bmp";
    cout << "Result test perimeter" << endl;
    test_perimeter(filename);
    cout << "Result test mat_to_vector" << endl;
    test_mat_to_vector(filename);

/*
	srand (time(NULL));
	calculErreur(methodeBidon,"methodeBidon"); */
	return 0;
}
