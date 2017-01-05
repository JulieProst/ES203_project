#ifndef TESTS
#define TESTS

#include <iostream>
#include "matrice.h"
#include "readbmp.h"
#include "Characteristiques.h"

void test_perimeter(const std::string& filename);
void test_mat_to_vector(const std::string& filename);
void test_nbr_trous(const std::string& filename);

std::ostream& operator<<(std::ostream& oss, const std::vector<int>& M);


#endif // TESTS
