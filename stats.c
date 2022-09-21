#include <math.h>
#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

int main(void)
{
	Stats_t stats = {0, 0, 0};
	const float data[] = {1.5, 8.9, 3.2, 4.5};
	const float maxThreshold = 10.2;
	int dataLen = sizeof(data)/sizeof(float);

	stats = compute_statistics(data, dataLen);

	check_and_alert(maxThreshold, alerters, stats);

	return 0;
}

Stats_t compute_statistics(const float* numberset, int setlength)
{
	Stats_t s = {0, 0, 0};
	int i = 0;

	if (setlength > 0)
	{
		s.min = numberset[0];

		for (i; i < setlength; i++)
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

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats_t computedStats)
{
	if (computedStats.max > maxThreshold)
	{
		alerters[0]();
		alerters[1]();
	}
}
