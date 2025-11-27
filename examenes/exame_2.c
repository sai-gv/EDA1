#include <stdio.h>
#include <stdlib.h>

int maximo_recursivo(int A[], int inicio, int fin) {
    
    if (inicio == fin) {
        return A[inicio];
    }
    
    if (inicio > fin) {
        return A[inicio]; 
    }

    int medio = inicio + (fin - inicio) / 2;
    
    int max_izquierdo = maximo_recursivo(A, inicio, medio);
    int max_derecho = maximo_recursivo(A, medio + 1, fin);
    
    if (max_izquierdo > max_derecho) {
        return max_izquierdo;
    } else {
        return max_derecho;
    }
}

int main() {
    int n, i;
    int *lista;
    int resultado;

    printf("Ingresa el tamaño de la lista: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: El tamaño debe ser un entero positivo.\n");
        return 1;
    }

    lista = (int *)malloc(n * sizeof(int));
    if (lista == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    printf("Ingresa los elementos:\n");
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        if (scanf("%d", &lista[i]) != 1) {
            printf("Error: Ingresa un número entero válido.\n");
            free(lista);
            return 1;
        }
    }

    resultado = maximo_recursivo(lista, 0, n - 1);

    printf("\nEl valor máximo es: %d\n", resultado);

    free(lista);

    return 0;
}