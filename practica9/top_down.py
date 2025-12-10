def fib_topdown(n, memoria=None, depth=0):
    if memoria is None:
        memoria = {}

    tab = "   " * depth

    # Ya registrado
    if n in memoria:
        print(f"{tab}↳ f({n}) recuperado: {memoria[n]}")
        return memoria[n]

    # Casos base
    if n <= 1:
        memoria[n] = n
        print(f"{tab}Caso base f({n}) = {n}")
        return n

    print(f"{tab}Descomponiendo f({n}) en f({n-1}) + f({n-2})")

    izquierda  = fib_topdown(n-1, memoria, depth+1)
    derecha    = fib_topdown(n-2, memoria, depth+1)

    memoria[n] = izquierda + derecha
    print(f"{tab}Registrado f({n}) = {memoria[n]}")
    return memoria[n]


print("\n=== TOP-DOWN FIBONACCI ===")
resultado = fib_topdown(10)
print(f"\nResultado final: {resultado}\n")
