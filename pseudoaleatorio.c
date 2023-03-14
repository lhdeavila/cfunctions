/* Pseudoaleatorio */
#include <stdio.h>

unsigned long int next = 1;

int rand(void){
    next = next * 1103515245 + 12345;
    return ( unsigned int )(next/65536);
}

void srand(unsigned int seed){
    next = seed;
}

main() {
    printf("%d", rand);
}