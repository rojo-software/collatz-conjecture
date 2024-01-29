
def linear_method(n):
    val = n
    iterations = 0
    while (val > 1):
        if (val % 2):
            val = 3 * val + 1
        else:
            val = val / 2

        iterations+=1

    return iterations          

def recursive_method(n):
    if (n < 2): # 1, but also catch -ve numbers
        return 0
    else:
        if (n % 2):
            return 1 + recursive_method(3*n + 1)
        else:
            return 1 + recursive_method(n / 2)     

iterations_dict = {}
def cache_method(n):
    
    current_value = n
    iterations = 0
    while (current_value > 1):
        cached_iterations = iterations_dict.get(current_value)

        if cached_iterations is not None:
            iterations = iterations + cached_iterations
            break # finish the loop here
        else:
            if (current_value % 2):
                current_value = 3 * current_value + 1
            else:
                current_value = current_value / 2

            iterations+=1

    iterations_dict[n] = iterations;
    return iterations     
