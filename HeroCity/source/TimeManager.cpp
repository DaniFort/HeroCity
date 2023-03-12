#include "TimeManager.h"

bool TimeManager::CheckHour()
{
	if (currentHour > 23)
	{
		currentHour = 0;
		currentDay++;
		weekDay++;
		if (weekDay > 7)
			weekDay = 1;
		if (currentDay >= totalDays)
			return false;
		else
			return true;
	}
}
