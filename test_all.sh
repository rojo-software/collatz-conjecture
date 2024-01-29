#!/usr/bin/bash

N_MAX=1000

echo "**** Python, calculating upto ${N_MAX} ****"

echo "Linear:"
time python3 python/test.py ${N_MAX} linear

echo ""
echo "Recursive:"
time python3 python/test.py ${N_MAX} recursive

echo ""
echo "Cache:"
time python3 python/test.py ${N_MAX} cache

echo ""
echo ""
echo "**** C, calculating upto ${N_MAX} ****"

echo "Compiling C code..."
cd c;
gcc collatz.c test.c -o test.exe
cd ..

echo ""

echo "Linear:"
time c/test.exe ${N_MAX} linear

echo ""
echo "Recursive:"
time c/test.exe ${N_MAX} recursive

echo ""
echo "Cache:"
time c/test.exe ${N_MAX} cache