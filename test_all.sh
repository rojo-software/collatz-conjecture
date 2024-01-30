#!/usr/bin/bash

N_MAX=2000
REPETITIONS=20

echo "**** Compiling C code... ****"
cd c
make clean
make
cd ..
echo ""


echo "**** Python, calculating upto ${N_MAX} with ${REPETITIONS} repeats ****"

echo "Linear:"
time python3 python/test.py ${N_MAX} linear ${REPETITIONS}

echo ""
echo "Recursive:"
time python3 python/test.py ${N_MAX} recursive ${REPETITIONS}

echo ""
echo "Cache:"
time python3 python/test.py ${N_MAX} cache ${REPETITIONS}

echo ""
echo ""
echo "**** C, calculating upto ${N_MAX} with ${REPETITIONS} repeats ****"

echo "Linear:"
time c/test.exe ${N_MAX} linear ${REPETITIONS}

echo ""
echo "Recursive:"
time c/test.exe ${N_MAX} recursive ${REPETITIONS}

echo ""
echo "Cache:"
time c/test.exe ${N_MAX} cache ${REPETITIONS}

echo ""
echo ""
echo "**** JavaScript, calculating upto ${N_MAX} with ${REPETITIONS} repeats ****"

echo "Linear:"
time node javascript/test.js ${N_MAX} linear ${REPETITIONS}

echo ""
echo "Cache:"
time node javascript/test.js ${N_MAX} cache ${REPETITIONS}