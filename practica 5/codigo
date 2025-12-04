#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int tope;
} Pila;

void inicializar_pila(Pila *p) {
    p->tope = -1;
    printf("Pila inicializada vacía.\n");
}

void mostrar_pila(Pila *p) {
    printf("Pila actual: [ ");
    for (int i = 0; i <= p->tope; i++) {
        printf("%d ", p->datos[i]);
    }
    printf("] (Tope: %d)\n", p->tope);
}

void push(Pila *p, int valor) {
    if (p->tope >= MAX - 1) {
        printf("Error: Pila llena. No se puede insertar %d.\n", valor);
        return;
    }
    p->tope++;
    p->datos[p->tope] = valor;
    printf("PUSH %d. ", valor);
    mostrar_pila(p);
}

int pop(Pila *p) {
    if (p->tope < 0) {
        printf("Error: Pila vacía. No se puede extraer.\n");
        return -9999;
    }
    int valor_extraido = p->datos[p->tope];
    p->tope--;
    printf("POP %d. ", valor_extraido);
    mostrar_pila(p);
    return valor_extraido;
}

typedef struct {
    int datos[MAX];
    int frente;
    int final;
} Cola;

void inicializar_cola(Cola *c) {
    c->frente = 0;
    c->final = -1;
    printf("\nCola inicializada vacía.\n");
}

void mostrar_cola(Cola *c) {
    printf("Cola actual: [ ");
    if (c->final >= c->frente) {
        for (int i = c->frente; i <= c->final; i++) {
            printf("%d ", c->datos[i]);
        }
    }
    printf("] (Frente: %d, Final: %d)\n", c->frente, c->final);
}

void enqueue(Cola *c, int valor) {
    if (c->final >= MAX - 1) {
        printf("Error: Cola llena. No se puede insertar %d.\n", valor);
        return;
    }
    c->final++;
    c->datos[c->final] = valor;
    printf("ENQUEUE %d. ", valor);
    mostrar_cola(c);
}

int dequeue(Cola *c) {
    if (c->final < c->frente) {
        printf("Error: Cola vacía. No se puede extraer.\n");
        return -9999;
    }
    int valor_extraido = c->datos[c->frente];
    c->frente++;
    
    if (c->frente > c->final) {
        c->frente = 0;
        c->final = -1;
    }
    
    printf("DEQUEUE %d. ", valor_extraido);
    mostrar_cola(c);
    return valor_extraido;
}

int main() {
    Pila mi_pila;
    Cola mi_cola;
    int num_elementos, valor;
    
    printf("======= PILA (LIFO) =======\n");
    inicializar_pila(&mi_pila);

    printf("\n¿Cuántos elementos desea apilar (máximo %d)? ", MAX);
    scanf("%d", &num_elementos);
    if (num_elementos > MAX) num_elementos = MAX; 
    
    for (int i = 0; i < num_elementos; i++) {
        printf("Valor a apilar: ");
        scanf("%d", &valor);
        push(&mi_pila, valor);
    }
    
    printf("\n¿Cuántos elementos desea desapilar? ");
    scanf("%d", &num_elementos);
    for (int i = 0; i < num_elementos; i++) {
        pop(&mi_pila);
    }

    printf("\n======= COLA (FIFO) =======\n");
    inicializar_cola(&mi_cola);

    printf("\n¿Cuántos elementos desea encolar (máximo %d)? ", MAX);
    scanf("%d", &num_elementos);
    if (num_elementos > MAX) num_elementos = MAX; 
    
    for (int i = 0; i < num_elementos; i++) {
        printf("Valor a encolar: ");
        scanf("%d", &valor);
        enqueue(&mi_cola, valor);
    }

    printf("\n¿Cuántos elementos desea desencolar? ");
    scanf("%d", &num_elementos);
    for (int i = 0; i < num_elementos; i++) {
        dequeue(&mi_cola);
    }
    
    printf("\n============================================\n");
    printf("Resumen: La Pila sigue el orden LIFO. La Cola sigue el orden FIFO.\n");
    printf("============================================\n");

    return 0;
}
