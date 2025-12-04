#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

struct Nodo* crearNodo(int valor) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
    return nuevo;
}

void insertarInicio(struct Nodo **inicio, int valor) {
    struct Nodo* nuevo = crearNodo(valor);
    
    nuevo->siguiente = *inicio;
    
    if (*inicio != NULL) {
        (*inicio)->anterior = nuevo;
    }
    *inicio = nuevo;
}

void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo* nuevo = crearNodo(valor);
    
    if (*inicio == NULL) {
        *inicio = nuevo;
        return;
    }
    
    struct Nodo *temp = *inicio;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    
    temp->siguiente = nuevo;
    nuevo->anterior = temp;
}

void recorrerAdelante(struct Nodo *inicio) {
    printf("\nRecorrido Adelante: ");
    if (inicio == NULL) {
        printf("Lista vacía.");
        return;
    }
    struct Nodo *actual = inicio;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void recorrerAtras(struct Nodo *inicio) {
    printf("Recorrido Atrás: ");
    if (inicio == NULL) {
        printf("Lista vacía.");
        return;
    }
    
    struct Nodo *ultimo = inicio;
    while (ultimo->siguiente != NULL) {
        ultimo = ultimo->siguiente;
    }
    
    struct Nodo *actual = ultimo;
    while (actual != NULL) {
        printf("%d <- ", actual->dato);
        actual = actual->anterior;
    }
    printf("NULL\n");
}

void eliminar(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) return;

    struct Nodo *actual = *inicio;
    
    while (actual != NULL && actual->dato != valor) {
        actual = actual->siguiente;
    }
    
    if (actual == NULL) {
        printf("Valor %d no encontrado.\n", valor);
        return;
    }
    
    if (actual == *inicio) {
        *inicio = actual->siguiente;
        if (*inicio != NULL) {
            (*inicio)->anterior = NULL;
        }
    } 
    else {
        if (actual->anterior != NULL) {
            actual->anterior->siguiente = actual->siguiente;
        }
        
        if (actual->siguiente != NULL) {
            actual->siguiente->anterior = actual->anterior;
        }
    }
    
    printf("Nodo con valor %d eliminado.\n", actual->dato);
    free(actual);
}

void liberar(struct Nodo **inicio) {
    struct Nodo *actual = *inicio;
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

    printf("--- Lista Doblemente Ligada (DLL) ---\n");

    printf("\n¿Cuántos valores desea insertar al inicio? ");
    scanf("%d", &num_nodos);
    for (int i = 0; i < num_nodos; i++) {
        printf("Valor %d: ", i + 1);
        int valor;
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
    }
    recorrerAdelante(inicio);

    printf("\n¿Cuántos valores desea insertar al final? ");
    scanf("%d", &num_nodos);
    for (int i = 0; i < num_nodos; i++) {
        printf("Valor %d: ", i + 1);
        int valor;
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
    }
    recorrerAdelante(inicio);

    recorrerAtras(inicio);

    printf("\nIngrese el valor a eliminar: ");
    scanf("%d", &valor_eliminar);
    eliminar(&inicio, valor_eliminar);
    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    liberar(&inicio);

    return 0;
}
