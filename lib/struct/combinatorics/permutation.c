#include <assert.h>

typedef struct
{
    size_t size;
    size_t *data;
} permutation;

/*
    Calculate parity of a permutation
    The algorithm is taken from "Combinatorics for programmers" Lipskij, pg. 11

    output: 
        true means the even permutation, false - odd
    remarks:
        O(n) in time
        O(n) in memory p->size * sizeof(char) (can be reduced in 8 times)
*/
bool
permutation_parity(const permutation *p)
{
    bool sgn;
    size_t i, j;
    char *status;

    status = (char *)calloc(p->size, sizeof(char));
    assert(status);
    for(i = 0; i < p->size; i++)
        if (status[i])
        {
            j = p->data[i];
            while(j != i)
            {
                status[j] = false;
                sgn = !sgn;
                j = p->data[j];
            }
        }

   free(status);
   return sgn;
}
