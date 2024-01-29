#!/usr/bin/bash

N_MAX=2048

echo "**** Python, calculating upto ${N_MAX} ****"

echo "Linear:"
time python3 python/test.py ${N_MAX} linear

echo ""
echo "Recursive:"
time python3 python/test.py ${N_MAX} recursive

echo ""
echo "Cache:"
time python3 python/test.py ${N_MAX} cache
