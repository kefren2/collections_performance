# collections_performance
Simple C++ test to measure the performance of vectors, sets, lists...

All that is does now is create a collection with 10M elements, and do 5000 finds for each collection.

Example output (all numbers are expressed in microseconds):

Testing Vector
-----
Creation: 497888
Find: 159129723


Testing Set
-----
Creation: 11593597
Find: 85196


Testing Unordered Set
-----
Creation: 6629626
Find: 4237


Testing List
-----
Creation: 1820289
Find: 171738921


