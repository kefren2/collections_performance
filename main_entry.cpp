#include "stop_clock.h"
#include "test_set.h"

#include <assert.h>
#include <iostream>

#define TOTAL  10000000

template <template<typename...> class C, typename T>
void
TestOne(std::string name)
{
	TestUtils::StopClock clock;
	unsigned long duration;

	std::cout << "Testing " << name << std::endl << "-----" << std::endl;

	Testing::Test_Set<C, T> c(0);
	clock.Start();
	c.AddSequential(TOTAL);
	duration = clock.Stop();
	std::cout << "Creation: " << duration << std::endl;

	clock.Start();
	for (size_t i = 0; i < TOTAL; i += 2000)
		assert(c.Find(i) == true);
	duration = clock.Stop();
	std::cout << "Find: " << duration << std::endl << std::endl << std::endl;
}

int
main()
{
	TestOne<std::vector, int>("Vector");
	TestOne<std::set, int>("Set");
	TestOne<std::unordered_set, int>("Unordered Set");
	TestOne<std::list, int>("List");
	return 0;
}
