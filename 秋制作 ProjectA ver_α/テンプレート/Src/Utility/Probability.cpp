#include "Probability.h"
#include <stdlib.h>

bool Probability::ProbabilityJudge(double probability_)
{
	static double Probability = probability_; // Šm—¦

	if ((double)rand() / RAND_MAX < Probability) {
		return true;
	}

	return false;
}