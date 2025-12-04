#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

struct Nodo* crearNodoCircular(int valor) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->anterior = nuevo;
    nuevo->siguiente = nuevo;
    return nuevo;
}

void insertarFinalCircular(struct Nodo **inicio, int valor) {
    struct Nodo* nuevo = crearNodoCircular(valor);
    
    if (*inicio == NULL) {
        *inicio = nuevo;
        return;
    }
    
    struct Nodo *ultimo = (*inicio)->anterior;
    
    nuevo->siguiente = *inicio;
    nuevo->anterior = ultimo;
    
    (*inicio)->anterior = nuevo;
    ultimo->siguiente = nuevo;
}

void recorrerCircular(struct Nodo *inicio) {
    printf("\nRecorrido Circular: ");
    if (inicio == NULL) {
        printf("Lista vacía.");
        return;
    }
    
    struct Nodo *actual = inicio;
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != inicio);
    printf("...vuelve al inicio.\n");
}

void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) return;

    struct Nodo *actual = *inicio;
    
    do {
        if (actual->dato == valor) break;
        actual = actual->siguiente;
    } while (actual != *inicio);
    
    if (actual->dato != valor) {
        printf("Valor %d no encontrado.\n", valor);
        return;
    }
    
    if (actual == *inicio && actual->siguiente == *inicio) {
        free(actual);
        *inicio = NULL;
        printf("Único nodo con valor %d eliminado. Lista vacía.\n", valor);
        return;
    }

    actual->anterior->siguiente = actual->siguiente;
    actual->siguiente->anterior = actual->anterior;
    
    if (actual == *inicio) {
        *inicio = actual->siguiente;
    }
    
    printf("Nodo con valor %d eliminado.\n", actual->dato);
    free(actual);
}

void liberarCircular(struct Nodo **inicio) {
    if (*inicio == NULL) return;

    struct Nodo *actual = *inicio;
    struct Nodo *ultimo = (*inicio)->anterior;
    
    ultimo->siguiente = NULL; 
    
    struct Nodo *temp;
    
    while (actual != NULL) {
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    *inicio = NULL;
    printf("\nMemoria liberada correctamente.\n");
}

int main() {
    struct Nodo *inicio = NULL;
    int num_nodos, valor_eliminar;

    printf("--- Lista Doblemente Ligada Circular (CDLL) ---\n");

    printf("\n¿Cuántos valores desea insertar? ");
    scanf("%d", &num_nodos);
    for (int i = 0; i < num_nodos; i++) {
        printf("Valor %d: ", i + 1);
        int valor;
        scanf("%d", &valor);
        insertarFinalCircular(&inicio, valor);
    }

    recorrerCircular(inicio);

    printf("\nIngrese el valor a eliminar: ");
    scanf("%d", &valor_eliminar);
    eliminarCircular(&inicio, valor_eliminar);
    
    if (inicio != NULL) {
        recorrerCircular(inicio);
    } else {
        printf("La lista está vacía.\n");
    }

    liberarCircular(&inicio);

    return 0;
}
