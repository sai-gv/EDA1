#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int frente; 
    int final;  
    int tamano; 
} ColaCircular;

void inicializar_circular(ColaCircular *c) {
    c->frente = 0;
    c->final = 0;
    c->tamano = 0;
    printf("Cola circular inicializada.\n");
}

int isEmpty(ColaCircular *c) {
    return c->tamano == 0;
}

int isFull(ColaCircular *c) {
    return c->tamano == MAX;
}

void enqueue(ColaCircular *c, int valor) {
    if (isFull(c)) {
        printf("Error: Cola llena. No se puede encolar %d.\n", valor);
        return;
    }
    c->datos[c->final] = valor;
    c->final = (c->final + 1) % MAX; 
    c->tamano++;
    printf("ENQUEUE %d. ", valor);
}

int dequeue(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("Error: Cola vacía. No se puede desencolar.\n");
        return -9999;
    }
    int valor = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX; 
    c->tamano--;
    printf("DEQUEUE %d. ", valor);
    return valor;
}

int peek(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("Error: Cola vacía.\n");
        return -9999;
    }
    return c->datos[c->frente];
}

void printQueue(ColaCircular *c) {
    printf("Contenido: [");
    if (!isEmpty(c)) {
        int i = c->frente;
        for (int k = 0; k < c->tamano; k++) {
            printf(" %d", c->datos[i]);
            i = (i + 1) % MAX;
        }
    }
    printf(" ] (Frente: %d, Final: %d, Tamaño: %d)\n", c->frente, c->final, c->tamano);
}

int main() {
    ColaCircular cola;
    inicializar_circular(&cola);

    printf("\n--- Pruebas Iniciales ---\n");
    enqueue(&cola, 5); printQueue(&cola);
    enqueue(&cola, 10); printQueue(&cola);
    enqueue(&cola, 15); printQueue(&cola);

    dequeue(&cola); printQueue(&cola);

    printf("\n--- Pruebas de Reciclaje ---\n");
    enqueue(&cola, 20); printQueue(&cola);
    enqueue(&cola, 25); printQueue(&cola);
    
    enqueue(&cola, 30); printQueue(&cola);

    printf("\n--- Pruebas Finales ---\n");
    while(!isEmpty(&cola)) {
        dequeue(&cola); printQueue(&cola);
    }
    
    return 0;
}
