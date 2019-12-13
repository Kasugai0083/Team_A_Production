#include "DayController.h"

DayController* DayDifficulty() {
	static DayController Days;
	return &Days;
}