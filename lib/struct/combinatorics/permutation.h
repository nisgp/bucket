#include <assert.h>

typedef struct
{
    size_t size;
    size_t *data;
} permutation;

/*
    Calculate parity of a permutation

    true - even
    false - odd
*/
bool permutation_parity(const permutation *p);
