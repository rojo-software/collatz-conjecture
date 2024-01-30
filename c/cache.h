#ifndef CACHE_H
#define CACHE_H


#define UNDEFINED -1 // provide a value so we know item is undefined

void add_to_cache(int n, int iterations);
int get_from_cache(int n);
void initialise_cache(void);

#endif