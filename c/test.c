#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "collatz.h"

#define MAX_N 20000 // define an arbitrary limit
#define FALSE 0
#define TRUE 1

enum Algorithm {Linear, Recursive, Cache};

int parseCommandLine_N(char* arg) {
    int value = atoi(arg);
    if (value < 1 || value > MAX_N) {
        printf("Value of N: %s is not valid\n", arg);
        exit(-1);
    }
    return value;  
}

enum Algorithm parseCommandLine_Algo(char* arg) {

    enum Algorithm value; 
    if (!strcmp(arg, "linear")) {
        value = Linear;
    }
    else if (!strcmp(arg, "recursive")) {
        value = Recursive;
    }
    else if (!strcmp(arg, "cache")) {
        value = Cache;
    }
    else {
        printf("Value of algorithm: %s is not valid\n", arg);
        exit(-1);
    }
    return value;

}

void main( int argc, char *argv[] )  {

   int N;
   enum Algorithm algorithm;
   int debug = FALSE;  

   if( argc == 3 || argc == 4)  {
      N = parseCommandLine_N(argv[1]);
      algorithm = parseCommandLine_Algo(argv[2]);

      if (argc == 4) {
        debug = TRUE;
      }

   }
   else {
      printf("Run Collatz over given range with selected algorithm\n");
      printf("usage: test.exe N {linear,recursive,cache} --debug\n");
      exit(0);
   }

   switch(algorithm) {
    case Linear: {

        for (int n = 2; n <= N; n++) {
            int result = linear_method(n);
            if (debug) {
                printf("%d %d\n", n, result);
            }
        }
        break;
    }
    case Recursive: {

        for (int n = 2; n <= N; n++) {
            int result = recursive_method(n);
            if (debug) {
                printf("%d %d\n", n, result);
            }
        }
        break;
    }
    case Cache: {

        cache_initialize();
        for (int n = 2; n <= N; n++) {
            int result = cache_method(n);
            if (debug) {
                printf("%d %d\n", n, result);
            }
        }
        break;
    }

    default: {
        // do nothing
        }
    }
}