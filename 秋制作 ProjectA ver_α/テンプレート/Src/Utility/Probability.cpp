#include "Probability.h"
#include <stdlib.h>
#include <random>

bool Probability::GetRandomValue(int floor, int ceil, int val) {

	std::random_device seed;
	std::mt19937_64 mt(seed());
	std::uniform_int_distribution<>dist(floor, ceil);
	
	int res =  dist(mt);
	if (res == val) {
		return true;
	}
	return false;

}