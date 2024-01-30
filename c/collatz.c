#include "cache.h"

int linear_method(int n) {
    int current_value = n;
    int iterations = 0;
    while (current_value > 1) {
        if (current_value & 0x1) {
            current_value = 3 * current_value + 1;
        }
        else {
            current_value = current_value >> 1;
        }

        iterations++;
    }

    return iterations;  
}

int recursive_method(int n) {
    if (n < 2) { // Terminating condition, also catch -ve numbers
        return 0;
    }
    else {
        if (n & 0x1) {
            return 1 + recursive_method(3 * n + 1);
        }
        else {
            return 1 + recursive_method(n >> 1);
        }
    }
}

static int cache_initialised = 0;

int cache_method(int n) {

    if (!cache_initialised) {
        initialise_cache();
        cache_initialised = 1;
    }

    int current_value = n;
    int iterations = 0;
    while (current_value > 1) {
        int cached_iterations = get_from_cache(current_value);

        if (cached_iterations != UNDEFINED) {
            iterations = iterations + cached_iterations;
            break; // finish the loop here
        }
        else {
            if (current_value & 0x1) {
                current_value = 3 * current_value + 1;
            }
            else {
                current_value = current_value >> 1;
            }

            iterations+=1;
        }

    }

    add_to_cache(n, iterations);
    return iterations;   
}