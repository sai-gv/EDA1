def calcular_cambio_optimo(monto_a_cambiar, conjunto_denominaciones):
    conjunto_denominaciones.sort(reverse=True)
    
    resultado_cambio = []
    
    for valor_billete in conjunto_denominaciones:
        if monto_a_cambiar == 0:
            break
            
        conteo_unidades = monto_a_cambiar // valor_billete
        
        if conteo_unidades > 0:
            resultado_cambio.append([valor_billete, conteo_unidades])
            
            monto_a_cambiar %= valor_billete
            
    return resultado_cambio

if __name__ == "__main__":
    print("--- Algoritmo Greedy (Cambio de Monedas) ---")
    denominaciones_mx = [500, 200, 100, 50, 20, 5, 1]
    
    print(f"Cambio para 1000: {calcular_cambio_optimo(1000, denominaciones_mx.copy())}")
    print(f"Cambio para 500: {calcular_cambio_optimo(500, denominaciones_mx.copy())}")
    print(f"Cambio para 300: {calcular_cambio_optimo(300, [50, 20, 5, 1].copy())}")
    print(f"Cambio para 200 (solo 5): {calcular_cambio_optimo(200, [5].copy())}")
    print(f"Cambio para 98: {calcular_cambio_optimo(98, [50, 20, 5, 1].copy())}")
