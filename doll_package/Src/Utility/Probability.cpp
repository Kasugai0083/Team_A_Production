#include "Probability.h"
#include <stdlib.h>
#include <random>

bool Probability::GetRandomValue(int floor_, int ceil_, int val_) {

	std::random_device seed;
	std::mt19937_64 mt(seed());
	std::uniform_int_distribution<>dist(floor_, ceil_);
	
	int res =  dist(mt);
	if (res == val_) {
		return true;
	}
	return false;

}