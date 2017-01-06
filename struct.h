#ifndef STRUCT
#define STRUCT

#include<vector>

struct Point{
	std::vector<int> coord;
	int etiquette;
};

enum TypeVision{
	WATCH,
	LEARN_AND_WATCH
};

#endif
