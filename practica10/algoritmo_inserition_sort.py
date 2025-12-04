def ordenar_por_insercion(lista_original):
    
    for indice_externo in range(1, len(lista_original)):
        elemento_actual = lista_original[indice_externo]
        posicion_recorrido = indice_externo
        
        print(f"-> Elemento a insertar: {elemento_actual}")
        
        while posicion_recorrido > 0 and lista_original[posicion_recorrido - 1] > elemento_actual:
            lista_original[posicion_recorrido] = lista_original[posicion_recorrido - 1]
            posicion_recorrido -= 1
            print(f"  Desplazamiento: {lista_original}")
            
        lista_original[posicion_recorrido] = elemento_actual
        print(f"  Inserción final: {lista_original}")
        print("-" * 20)
        
    return lista_original

if __name__ == "__main__":
    print("--- Algoritmo de Ordenamiento por Inserción ---")
    datos = [8, 5, 2, 9, 1]
    
    print(f"Lista inicial: {datos}")
    
    lista_ordenada = ordenar_por_insercion(datos)
    
    print(f"\nResultado final: {lista_ordenada}")
