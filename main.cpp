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

	srand (time(NULL));
	calculErreur(mat_to_vector,kppv,"walla",WATCH); 
	return 0;
}
