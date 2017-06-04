CXX=g++
CXXFLAGS=-std=c++11 -O3

SRCS=stop_clock.cpp main_entry.cpp
OBJS=${SRCS:S/.cpp/.o/g}
#OBJS=$(subst .cpp,.o,$(SRCS))

EXEC_NAME=collection_test
.PHONY: clean

all: do-test

do-test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC_NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXEC_NAME)
