def fib_bottomup(n):
    if n == 0:
        print("Serie generada: [0]")
        return 0
    if n == 1:
        print("Serie generada: [0, 1]")
        return 1

    serie = [0, 1]
    print("Construyendo tabla:")

    for i in range(2, n + 1):
        nuevo = serie[i-1] + serie[i-2]
        serie.append(nuevo)
        print(f" paso {i}: {serie}")

    print("\nSerie completa:", serie)
    return serie[n]


print("\n=== BOTTOM-UP FIBONACCI ===")
res = fib_bottomup(15)
print(f"\nResultado final: {res}\n")
