#include <stdio.h>

int main() {
    int n, i;
    int a[100];

    printf("Cuantos elementos tendra el arreglo (1 a 100): ");
    scanf("%d", &n);

    while(n < 1 || n > 100){
        printf("Valor invalido, intenta de nuevo: ");
        scanf("%d", &n);
    }

    for(i=0;i<n;i++){
        printf("Elemento %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("\nElementos del arreglo:\n");
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
