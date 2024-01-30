module.exports.linearMethod = function linearMethod(n) {
    let currentValue = n;
    let iterations = 0;
    while (currentValue > 1) {
        if (currentValue & 0x1) {
            currentValue = 3 * currentValue + 1;
        }
        else {
            currentValue = currentValue >> 1;
        }

        iterations++;
    }

    return iterations;  
}


const iterationsCache = {};

module.exports.cacheMethod = function cacheMethod(n) {
    let currentValue = n;
    let iterations = 0;
    while (currentValue > 1) {

        const cachedIterations = iterationsCache[currentValue];
        if (cachedIterations) {
            iterations = iterations + cachedIterations;
            break;
        }
        else {
            if (currentValue & 0x1) {
                currentValue = 3 * currentValue + 1;
            }
            else {
                currentValue = currentValue >> 1;
            }
    
            iterations++;
        }
    }

    iterationsCache[n] = iterations;

    return iterations;  
}
