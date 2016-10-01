#include "stop_clock.h"

namespace TestUtils {
unsigned long
StopClock::Stop()
{
	struct timeval tp2;

	gettimeofday(&tp2, NULL);
	return (tp2.tv_sec - tp.tv_sec) * 1000000 +
		tp2.tv_usec - tp.tv_usec;
}
}