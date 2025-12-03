#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_PROD 2

struct registro_filmico {
    char titulo[20];
    char categoria[20];
    int anio;
    int total_productores;
    char productores[MAX_PROD][20];
};

int main(void) {
    struct registro_filmico coleccion[MAX_ITEMS]; 
    int contador_films; 

    printf("¿Cuantos registros filmicos desea ingresar (Minimo 1)? ");
    scanf("%d", &contador_films); 
    
    if (contador_films < 1 || contador_films > MAX_ITEMS) {
        printf("Limite no valido o excedido. Saliendo.\n");
        return 0;
    }

    for (int idx_film = 0; idx_film < contador_films; idx_film++) { 
        printf("\n** Registro %d **\n", idx_film + 1);
        
        printf("Titulo: ");
        scanf(" %19[^\n]", coleccion[idx_film].titulo);
        
        printf("Categoria: ");
        scanf(" %19[^\n]", coleccion[idx_film].categoria);  
        
        printf("Año de lanzamiento: ");
        scanf("%d", &coleccion[idx_film].anio);
        
        printf("Cantidad de productores (Maximo %d): ", MAX_PROD);
        scanf("%d", &coleccion[idx_film].total_productores);

        if (coleccion[idx_film].total_productores >= 1 && coleccion[idx_film].total_productores <= MAX_PROD) {
            for (int idx_prod = 0; idx_prod < coleccion[idx_film].total_productores; idx_prod++) { 
                printf("Nombre del productor %d: ", idx_prod + 1);
                scanf(" %19[^\n]", coleccion[idx_film].productores[idx_prod]);
            }
        } else {
            printf("Cantidad de productores no permitida. Error.\n");
            return 0; 
        }
    }

    printf("\n####### Reporte de la Coleccion #######\n");
    for (int i = contador_films - 1; i >= 0; i--) { 
        printf("Film: %s\n", coleccion[i].titulo);
        printf("Categoria: %s\n", coleccion[i].categoria);
        printf("Año: %d\n", coleccion[i].anio);
        printf("Productores (%d):\n", coleccion[i].total_productores);
        for (int j = 0; j < coleccion[i].total_productores; j++) {
            printf("  - %s\n", coleccion[i].productores[j]);
        }
    }

    int opcion_principal, tipo_busqueda;
    char valor_buscado[20];

    printf("\n¿Desea realizar una consulta especifica? (Si=1, No=2): ");
    scanf("%d", &opcion_principal);

    if (opcion_principal == 1) {
        printf("Menu de Consulta:\n 1. Titulo\n 2. Año\n 3. Categoria\n 4. Productor\n");
        scanf("%d", &tipo_busqueda);

        switch (tipo_busqueda) {
            case 1: 
                printf("Ingrese el titulo: ");
                scanf(" %19[^\n]", valor_buscado);
                for (int i = 0; i < contador_films; i++) {
                    if (strcmp(coleccion[i].titulo, valor_buscado) == 0) { 
                        printf("\nCoincidencia encontrada:\n");
                        printf("Titulo: %s\n", coleccion[i].titulo);
                        printf("Categoria: %s\n", coleccion[i].categoria);
                        printf("Año: %d\n", coleccion[i].anio);
                        for (int j = 0; j < coleccion[i].total_productores; j++) {
                            printf("  - %s\n", coleccion[i].productores[j]);
                        }
                    }
                }
                break;

            case 2: {
                int anio_buscado;
                printf("Ingrese el año: ");
                scanf("%d", &anio_buscado);
                for (int i = 0; i < contador_films; i++) {
                    if (coleccion[i].anio == anio_buscado) {
                        printf("\nCoincidencia encontrada:\n");
                        printf("Titulo: %s\n", coleccion[i].titulo);
                        printf("Categoria: %s\n", coleccion[i].categoria);
                        printf("Año: %d\n", coleccion[i].anio);
                        for (int j = 0; j < coleccion[i].total_productores; j++) {
                            printf("  - %s\n", coleccion[i].productores[j]);
                        }
                    }
                }
                break;
            }
            
            case 3: 
                printf("Ingrese la categoria: ");
                scanf(" %19[^\n]", valor_buscado);
                for (int i = 0; i < contador_films; i++) {
                    if (strcmp(coleccion[i].categoria, valor_buscado) == 0) {
                        printf("\nCoincidencia encontrada:\n");
                        printf("Titulo: %s\n", coleccion[i].titulo);
                        printf("Categoria: %s\n", coleccion[i].categoria);
                        printf("Año: %d\n", coleccion[i].anio);
                        for (int j = 0; j < coleccion[i].total_productores; j++) {
                            printf("  - %s\n", coleccion[i].productores[j]);
                        }
                    }
                }
                break;

            case 4: 
                printf("Ingrese el nombre del productor: ");
                scanf(" %19[^\n]", valor_buscado);
                for (int i = 0; i < contador_films; i++) {
                    for (int j = 0; j < coleccion[i].total_productores; j++) {
                        if (strcmp(coleccion[i].productores[j], valor_buscado) == 0) {
                            printf("\nCoincidencia encontrada:\n");
                            printf("Titulo: %s\n", coleccion[i].titulo);
                            printf("Categoria: %s\n", coleccion[i].categoria);
                            printf("Año: %d\n", coleccion[i].anio);
                            for (int k = 0; k < coleccion[i].total_productores; k++) {
                                printf("  - %s\n", coleccion[i].productores[k]);
                            }
                        }
                    }
                }
                break;

            default:
                printf("Opcion de consulta no valida.\n");
                break;
        }
    } else {
        printf("Saliendo del programa.\n");
    }

    return 0;
}
