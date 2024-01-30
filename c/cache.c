#include "cache.h"

//
// Simple cache - rather wasteful of memory but faster than a key-value store
// We don't cache very large values of N as these require more storage
//
#define MAX_N 250505 // define sensible cache limit (see https://www.dcode.fr/collatz-conjecture)
static int iterations_cache[MAX_N];

void add_to_cache(int n, int iterations) {
    if (n < MAX_N) {
        iterations_cache[n] = iterations;
    }

}
int get_from_cache(int n) {
    if (n < MAX_N) {
        return iterations_cache[n];
    }
    else {
        return UNDEFINED;
    }
}

void initialise_cache(void) {
    for (int i =0; i < MAX_N; i++)
    iterations_cache[i] = UNDEFINED;
}