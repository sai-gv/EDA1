#include <stdio.h>

int main() {
    int numeros[5] = {2, 4, 6, 8, 10};
    int *ap = numeros; // ap apunta al primer elemento

    printf("1) numeros[1] = %d\n", numeros[1]);     
    printf("2) *(numeros+3) = %d\n", *(numeros+3)); 
    printf("3) *ap++ = %d\n", *ap++);               
    printf("4) *++ap = %d\n", *++ap);               
    printf("5) ap[1] = %d\n", ap[1]);               
    printf("6) *(ap+=2) = %d\n", *(ap+=2));         
    printf("7) ap-numeros = %ld\n", ap-numeros);    

    return 0;
}
