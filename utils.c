//Dan Dominic Staicu 311CA
#include "utils.h"

//swaps any kind of variables
void swap_any(void *a, void *b, size_t s)
{
    void *tmp = malloc(s);
    memcpy(tmp, a, s);
    memcpy(a, b, s);
    memcpy(b, tmp, s);
    free(tmp);
}
