#include "alerters.h"

typedef struct Stats_s
{
	float average;
	float min;
	float max;
} Stats_t;

typedef void (*alerter_funcptr)(void);

Stats_t compute_statistics(const float* numberset, int setlength);

void check_and_alert(float maxThreshold, alerter_funcptr alert_array[], Stats_t computedStats);

extern int emailAlertCallCount;
extern int ledAlertCallCount;
