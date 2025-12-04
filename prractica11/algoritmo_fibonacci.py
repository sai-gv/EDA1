def fibonacci_recursivo(n):
    if n <= 1:
        return n
    else:
        return fibonacci_recursivo(n-1) + fibonacci_recursivo(n-2)

posiciones = [7, 21, 40, 71, 94]

print("--- Secuencia de Fibonacci Recursiva ---")

for pos in posiciones:
    if pos < 35:
        resultado = fibonacci_recursivo(pos)
        print(f"Posición {pos}: {resultado}")
    else:
        print(f"Posición {pos}: (Extremadamente lento por recursión pura.)")

def fibonacci_iterativo(n):
    if n <= 1:
        return n
    a, b = 0, 1
    for _ in range(2, n + 1):
        a, b = b, a + b
    return b

print("\n--- Resultados de Posiciones Grandes (Iterativo) ---")

for pos in [40, 71, 94]:
    resultado = fibonacci_iterativo(pos)
    print(f"Posición {pos}: {resultado}")
