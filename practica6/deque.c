#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int frente; 
    int tamano;
} Deque;

void inicializar_deque(Deque *d) {
    d->frente = 0;
    d->tamano = 0;
    printf("Cola Doble (Deque) inicializada.\n");
}

int is_empty_deque(Deque *d) {
    return d->tamano == 0;
}

int is_full_deque(Deque *d) {
    return d->tamano == MAX;
}

int calcular_final(Deque *d) {
    return (d->frente + d->tamano - 1 + MAX) % MAX;
}

void insert_front(Deque *d, int valor) {
    if (is_full_deque(d)) {
        printf("Error: Deque lleno. No se puede insertar %d.\n", valor);
        return;
    }
    d->frente = (d->frente - 1 + MAX) % MAX; 
    d->datos[d->frente] = valor;
    d->tamano++;
    printf("INSERT_FRONT %d. ", valor);
}

void insert_rear(Deque *d, int valor) {
    if (is_full_deque(d)) {
        printf("Error: Deque lleno. No se puede insertar %d.\n", valor);
        return;
    }
    int rear_pos = (d->frente + d->tamano) % MAX; 
    d->datos[rear_pos] = valor;
    d->tamano++;
    printf("INSERT_REAR %d. ", valor);
}

int delete_front(Deque *d) {
    if (is_empty_deque(d)) {
        printf("Error: Deque vacío. No se puede extraer del frente.\n");
        return -9999;
    }
    int valor = d->datos[d->frente];
    d->frente = (d->frente + 1) % MAX; 
    d->tamano--;
    printf("DELETE_FRONT %d. ", valor);
    return valor;
}

int delete_rear(Deque *d) {
    if (is_empty_deque(d)) {
        printf("Error: Deque vacío. No se puede extraer del final.\n");
        return -9999;
    }
    int valor = d->datos[calcular_final(d)];
    d->tamano--;
    printf("DELETE_REAR %d. ", valor);
    return valor;
}

void printDeque(Deque *d) {
    printf("Contenido: [");
    if (!is_empty_deque(d)) {
        int i = d->frente;
        for (int k = 0; k < d->tamano; k++) {
            printf(" %d", d->datos[i]);
            i = (i + 1) % MAX;
        }
    }
    printf(" ] (Frente: %d, Final: %d, Tamaño: %d)\n", d->frente, calcular_final(d), d->tamano);
}

int main() {
    Deque deque;
    inicializar_deque(&deque);

    printf("\n--- Paso B3: Pruebas de Inserción ---\n");
    insert_front(&deque, 10); printDeque(&deque); 
    insert_rear(&deque, 15); printDeque(&deque);
    insert_rear(&deque, 20); printDeque(&deque);
    insert_front(&deque, 30); printDeque(&deque);
    insert_rear(&deque, 40); printDeque(&deque);

    printf("\n--- Paso B3: Pruebas de Eliminación ---\n");
    delete_front(&deque); printDeque(&deque);
    delete_rear(&deque); printDeque(&deque);

    printf("\n--- Paso B3: Pruebas de Movimiento ---\n");
    insert_rear(&deque, 50); printDeque(&deque);
    insert_front(&deque, 5); printDeque(&deque);
    delete_front(&deque); printDeque(&deque); 
    delete_rear(&deque); printDeque(&deque);
    
    return 0;
}
