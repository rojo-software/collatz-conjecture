import collatz
import argparse
import sys



def main(argv):
    parser = argparse.ArgumentParser(description="Run Collatz over given range with selected algorithm.  NB There are no bounds checking so with very large N you could overflow or enter a recursive loop!")
    parser.add_argument("N", help="Calculate from 0 to N", type=int)
    parser.add_argument("algorithm", help="Algorithm to use", choices=['linear', 'recursive', 'cache'])
    parser.add_argument("repetitions", help="Number of repetitions", type=int)
    parser.add_argument("--debug", help="Print results", type=ascii)

    options = parser.parse_args(argv)

    if (options.algorithm == 'linear'):
        for r in range(options.repetitions):
            n = 2
            while n <= options.N:
                iterations = collatz.linear_method(n)
                if options.debug:
                    print(n, iterations)
                n+=1

    if (options.algorithm == 'recursive'):
        for r in range(options.repetitions):
            n = 2
            while n <= options.N:
                iterations = collatz.recursive_method(n)
                if options.debug:
                    print(n, iterations)
                n+=1

    if (options.algorithm == 'cache'):
        for r in range(options.repetitions):
            n = 2
            while n <= options.N:
                iterations = collatz.cache_method(n)
                if options.debug:
                    print(n, iterations)
                n+=1

if __name__ == '__main__':
    main(sys.argv[1:])