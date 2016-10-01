#ifndef __TEST_SET__
#define __TEST_SET__

#include <sys/types.h>
#include <stdlib.h>
#include <time.h>

#include <type_traits>

#include <list>
#include <set>
#include <unordered_set>
#include <vector>

namespace Testing {

template <template<typename...> class XSet, typename XType>
class Test_Set {

	XSet<XType> set;

public:
	Test_Set(size_t) {
		srandom(time(NULL));
	}
	~Test_Set() { }

	void AddRandom(size_t size) {
		for (size_t i = 0; i < size; i++)
			PushBack(random());
	}
	void AddSequential(size_t size) {
		for (size_t i = 0; i < size; i++)
			PushBack(i);
	}
	void AddFromMemory(XType *l, size_t size) {
		for (XType *t = l; t < l + size; t++)
			AddOne(*t);
	}

	void AddOne(const XType & v) {
		// use customized insert methods for each collection type
		if (std::is_base_of<std::vector<XType>, XSet<XType> >::value == true) {
			std::vector<XType> *p = (std::vector<XType>*)&set;
			p->push_back(v);
		} else if (std::is_base_of<std::set<XType>, XSet<XType> >::value == true) {
			std::set<XType> *p = (std::set<XType>*)&set;
			p->insert(v);
		} else if (std::is_base_of<std::unordered_set<XType>, XSet<XType> >::value == true) {
			std::unordered_set<XType> *p = (std::unordered_set<XType>*)&set;
			p->insert(v);
		} else if (std::is_base_of<std::list<XType>, XSet<XType> >::value == true) {
			std::list<XType> *p = (std::list<XType>*)&set;
			p->push_back(v);
		} else
			throw "Not implemented";
	}

	bool Find(const XType & v) {
		// use the instance find method for ordered collections
		if (std::is_base_of<std::set<XType>, XSet<XType> >::value == true) {
			std::set<XType> *p = (std::set<XType>*)&set;
			if (p->find(v) != p->end())
				return true;
		} else if (std::is_base_of<std::unordered_set<XType>, XSet<XType> >::value == true) {
			std::unordered_set<XType> *p = (std::unordered_set<XType>*)&set;
			if (p->find(v) != p->end())
				return true;
		} else if (std::find(set.begin(), set.end(), v) != set.end())
			return true;
		return false;
	}

private:
	void PushBack(long v) { AddOne(XType(v)); }
};

} // namespace

#endif
