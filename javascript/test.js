"use strict"

const collatz = require('./collatz');

const N = process.argv[2];
const algorithm = process.argv[3];
const repetitions = process.argv[4];
const debug = process.argv[5];

switch (algorithm) {
    case 'linear': {
        for (let r = 0; r < repetitions; r++) {
            for (let n = 2; n <= N; n++) {
                const value = collatz.linearMethod(n);
                if (debug) {
                    console.log(`${n} ${value}`);
                }
            }
        }
        break;
    }
    case 'cache': {
        for (let r = 0; r < repetitions; r++) {
            for (let n = 2; n <= N; n++) {
                const value = collatz.cacheMethod(n);
                if (debug) {
                    console.log(`${n} ${value}`);
                }
            }
        }
        break;
    }

    default: 
}
