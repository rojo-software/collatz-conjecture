#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "collatz.h"

#define MAX_N 20000 // define an arbitrary limit
#define FALSE 0
#define TRUE 1

enum Algorithm {Linear, Recursive, Cache};

int parse_command_line_N(char* arg) {
    int value = atoi(arg);
    if (value < 1 || value > MAX_N) {
        printf("Value of N: %s is not valid\n", arg);
        exit(-1);
    }
    return value;  
}

enum Algorithm parse_command_line_Algo(char* arg) {

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

int parse_command_line_Reps(char* arg) {
    int value = atoi(arg);
    if (value > 100) {
        printf("Max 100 reps only");
        exit(-1);
    }
    return value;


}

void main( int argc, char *argv[] )  {

   int N, repetitions;
   enum Algorithm algorithm;
   int debug = FALSE;  

   if( argc == 4 || argc == 5)  {
      N = parse_command_line_N(argv[1]);
      algorithm = parse_command_line_Algo(argv[2]);
      repetitions = parse_command_line_Reps(argv[3]);

      if (argc == 5) {
        debug = TRUE;
      }

   }
   else {
      printf("Run Collatz over given range with selected algorithm.  Can repeat 'repetition' times\n");
      printf("usage: test.exe N {linear,recursive,cache} repetitions --debug\n");
      exit(0);
   }

   switch(algorithm) {
    case Linear: {

        for (int r = 0; r < repetitions; r++) {
            for (int n = 2; n <= N; n++) {
                int result = linear_method(n);
                if (debug) {
                    printf("%d %d\n", n, result);
                }
            }
        }
        break;
    }
    case Recursive: {

        for (int r = 0; r < repetitions; r++) {
            for (int n = 2; n <= N; n++) {
                int result = recursive_method(n);
                if (debug) {
                    printf("%d %d\n", n, result);
                }
            }
        }
        break;
    }
    case Cache: {

        for (int r = 0; r < repetitions; r++) {
            for (int n = 2; n <= N; n++) {
                int result = cache_method(n);
                if (debug) {
                    printf("%d %d\n", n, result);
                }
            }
        }
        break;
    }

    default: {
        // do nothing
        }
    }
}