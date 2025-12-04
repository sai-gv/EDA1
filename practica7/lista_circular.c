#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

struct Nodo* crearNodoCircular(int valor) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: Fallo en la asignación de memoria.\n");
        exit(EXIT_FAILURE);
    }
    nuevo->dato = valor;
    nuevo->siguiente = nuevo;
    return nuevo;
}

void insertarInicioCircular(struct Nodo **cabeza, int valor) {
    struct Nodo* nuevo = crearNodoCircular(valor);
    
    if (*cabeza == NULL) {
        *cabeza = nuevo;
        return;
    }
    
    struct Nodo *ultimo = *cabeza;
    while (ultimo->siguiente != *cabeza) {
        ultimo = ultimo->siguiente;
    }
    
    nuevo->siguiente = *cabeza;
    ultimo->siguiente = nuevo;
    
    *cabeza = nuevo;

    printf("Insertado %d.\n", valor);
}

void recorrerCircular(struct Nodo *cabeza) {
    printf("Lista Circular: ");
    if (cabeza == NULL) {
        printf("Vacía.\n");
        return;
    }
    
    struct Nodo *actual = cabeza;
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza);
    printf("Vuelve a %d.\n", cabeza->dato);
}

void eliminarCircular(struct Nodo **cabeza, int valor) {
    if (*cabeza == NULL) return;

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;
    
    do {
        if (actual->dato == valor) break;
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);

    if (actual->dato != valor) {
        printf("Valor %d no encontrado.\n", valor);
        return;
    }
    
    if (actual == *cabeza && anterior == NULL && actual->siguiente == *cabeza) {
        free(actual);
        *cabeza = NULL;
        printf("Eliminado %d. Lista vacía.\n", valor);
        return;
    }

    if (actual == *cabeza) {
        struct Nodo *ultimo = *cabeza;
        while (ultimo->siguiente != *cabeza) {
            ultimo = ultimo->siguiente;
        }
        
        *cabeza = actual->siguiente;
        ultimo->siguiente = *cabeza;
    } 
    else {
        anterior->siguiente = actual->siguiente;
    }
    
    printf("Eliminado %d.\n", valor);
    free(actual);
}

void liberarCircular(struct Nodo **cabeza) {
    if (*cabeza == NULL) return;

    struct Nodo *actual = *cabeza;
    struct Nodo *temp;
    struct Nodo *ultimo = (*cabeza)->siguiente;

    while(ultimo->siguiente != *cabeza) {
        ultimo = ultimo->siguiente;
    }
    ultimo->siguiente = NULL; 
    
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

    printf("--- Práctica 7: Lista Circular ---\n");

    printf("\n¿Cuántos valores desea insertar al inicio? ");
    scanf("%d", &num_valores);
    for (int i = 0; i < num_valores; i++) {
        int valor;
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicioCircular(&cabeza, valor);
    }

    printf("\n--- Recorrido Circular Inicial ---\n");
    recorrerCircular(cabeza);

    printf("\nIngrese el valor a eliminar: ");
    scanf("%d", &valor_eliminar);
    eliminarCircular(&cabeza, valor_eliminar);

    printf("\n--- Lista Actualizada ---\n");
    if (cabeza != NULL) {
        recorrerCircular(cabeza);
    } else {
        printf("Lista vacía.\n");
    }

    liberarCircular(&cabeza);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
