#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

struct Nodo* crearNodo(int valor) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: Fallo en la asignación de memoria.\n");
        exit(EXIT_FAILURE);
    }
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}

void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo* nuevo = crearNodo(valor);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
    printf("Insertado %d.\n", valor);
}

void recorrer(struct Nodo *cabeza) {
    printf("Lista: ");
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void eliminar(struct Nodo **cabeza, int valor) {
    if (*cabeza == NULL) return;

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;

    if (actual != NULL && actual->dato == valor) {
        *cabeza = actual->siguiente;
        free(actual);
        printf("Eliminado %d (Cabeza).\n", valor);
        return;
    }

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Valor %d no encontrado.\n", valor);
        return;
    }

    anterior->siguiente = actual->siguiente;
    free(actual);
    printf("Eliminado %d.\n", valor);
}

void liberar(struct Nodo **cabeza) {
    struct Nodo *actual = *cabeza;
    struct Nodo *temp;
    
    while (actual != NULL) {
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    *cabeza = NULL;
}

int main() {
    struct Nodo *cabeza = NULL;
    int num_valores, valor_eliminar;

    printf("--- Práctica 7: Lista Simple ---\n");

    printf("\n¿Cuántos valores desea insertar al inicio? ");
    scanf("%d", &num_valores);
    for (int i = 0; i < num_valores; i++) {
        int valor;
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
    }

    printf("\n--- Recorrido Inicial ---\n");
    recorrer(cabeza);

    printf("\nIngrese el valor a eliminar: ");
    scanf("%d", &valor_eliminar);
    eliminar(&cabeza, valor_eliminar);

    printf("\n--- Lista Actualizada ---\n");
    recorrer(cabeza);

    liberar(&cabeza);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
