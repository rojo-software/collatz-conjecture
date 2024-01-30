# collatz-conjecture
Benchmarking different algorithms & langugages for calculating values of the Collatz conjecture.  See https://www.dcode.fr/collatz-conjecture for some background information.

# Introduction

This module provides some very simple implementations for calculating the number of iterations of the 3*n + 1 algorithm required to end up at the value 1.  Each of the test harnesses will calculate the number of iterations for a range of values from 1:N.  It is possible to run this process multiple times so that statistically meaningful execution times can be seen.

There are 3 approaches used:
* Linear - brute force approach
* Recursive - also a brute force approach, appears more elegant but not any better than the linear approach
* Cached - exploits the repetition in the stages of the algorithm to use previously calculated values to short-cut to the correct solution

These are are coded in 3 langugages, using a similar code structure for each approach:
* Python
* C
* JavaScript (recursive approach not implemented)

The source code is structured with a directory for each language:
```
/python
/c
/javascript
```

The codebase assumes that you are using some kind of *nix style OS, with a GCC toolchain, nodeJS & Python installations.

To run all tests with simple time benchmarking run `test_all.sh` at the top level.

## Results

### Example results
* Running on a Linux VM sitting on top of Window using an i7 CPU @ 2.40GHz 
* Calculating N = 1 - 2000, repeated 20 times

Python
```
Linear: 2.503s
Recursive: 2.858s
Cache: 0.151s
```

C
```
Linear: 0.035s
Recursive: 0.067s
Cache: 0.002s
```

JavaScript
```
Linear: 0.228s
Cache: 0.128s
```

* As we'd expect the quickest approach is the cache method, followed by linear, then recursive.
* The benchmarking times show that the C code is much quicker than Python & JS.  No suprise there!
* For the linear approach the JS runs significantly quicker than Python, but this performance isn't repeated
for the cache case.  Not sure why this is, are lookups into a JS key-value store significantly slower than lookups into a Python dictionary?
* One thing to note is that calling the test with repetition means that the overhead of initialising the cache is only incurred on the first call, and subsequent calls should use a fully populated cache. 
