#include <math.h>
#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

Stats_t compute_statistics(const float* numberset, int setlength)
{
	Stats_t s = {0, 0, 0};
	int i;

	if (setlength > 0)
	{
		s.min = numberset[0];

		for (i = 0; i < setlength; i++)
		{
			s.average += numberset[i];

			if (numberset[i] > s.max)
			{
				s.max = numberset[i];
			}

			if (numberset[i] < s.min)
			{
				s.min = numberset[i];
			}
		}

		s.average /= setlength;
	}
	else
	{
		s.average = NAN;
		s.min = NAN;
		s.max = NAN;
	}

	return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alert_array[], Stats_t computedStats)
{
	if (computedStats.max > maxThreshold)
	{
		alert_array[0]();
		alert_array[1]();
	}
}
