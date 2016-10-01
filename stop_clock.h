#ifndef __STOP_CLOCK__
#define __STOP_CLOCK__

#include <sys/time.h>
#include <sys/types.h>

namespace TestUtils
{
class StopClock {
private:
	struct timeval tp;
public:
	void Start() { gettimeofday(&tp, NULL); }
	unsigned long Stop();
};
}

#endif