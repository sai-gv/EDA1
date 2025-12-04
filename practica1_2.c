#include <stdio.h>

int main() {
    int n, i;
    int a[100];
    int suma = 0;
    float promedio;
    int min, max;
    int posMin, posMax;

    printf("Cuantos elementos tendra el arreglo (1 a 100): ");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        printf("Elemento %d: ", i);
        scanf("%d", &a[i]);
        suma = suma + a[i];
    }

    min = a[0];
    max = a[0];
    posMin = 0;
    posMax = 0;

    for(i=1;i<n;i++){
        if(a[i] < min){
            min = a[i];
            posMin = i;
        }
        if(a[i] > max){
            max = a[i];
            posMax = i;
        }
    }

    promedio = (float)suma / n;

    printf("\nSuma: %d\n", suma);
    printf("Promedio: %.2f\n", promedio);
    printf("Minimo: %d en posicion %d\n", min, posMin);
    printf("Maximo: %d en posicion %d\n", max, posMax);

    return 0;
}
