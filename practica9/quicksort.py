def quicksort_dc(arreglo, nivel=0):
    margen = "   " * nivel
    print(f"{margen}→ Analizando: {arreglo}")

    if len(arreglo) <= 1:
        print(f"{margen}   Lista trivial, regreso {arreglo}\n")
        return arreglo

    piv = arreglo[len(arreglo)//3]  # pivote distinto pero válido
    print(f"{margen}   Usando pivote: {piv}")

    left  = []
    mid   = []
    right = []

    for elemento in arreglo:
        if elemento < piv:
            left.append(elemento)
        elif elemento > piv:
            right.append(elemento)
        else:
            mid.append(elemento)

    print(f"{margen}   <  {left}")
    print(f"{margen}   =  {mid}")
    print(f"{margen}   >  {right}\n")

    izq_orden  = quicksort_dc(left,  nivel+1)
    der_orden  = quicksort_dc(right, nivel+1)

    combinado = izq_orden + mid + der_orden
    print(f"{margen}   Combinado: {combinado}\n")

    return combinado


print("\n=== QUICKSORT (D&C) ===")
ordenado = quicksort_dc([8, 3, 9, 1, 4, 7, 6])
print("Resultado final:", ordenado)
print()
