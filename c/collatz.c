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

#define MAX_N 250505 // define cache limit (see https://www.dcode.fr/collatz-conjecture)
#define UNDEFINED -1 // provide a value so we know item is undefined
static int iterations_cache[MAX_N];

void cache_initialize(void) {
    for (int i =0; i < MAX_N; i++)
        iterations_cache[i] = UNDEFINED;
}

int cache_method(int n) {
    
    int current_value = n;
    int iterations = 0;
    while (current_value > 1) {
        int cached_iterations = iterations_cache[current_value];

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

    iterations_cache[n] = iterations;
    return iterations;   
}