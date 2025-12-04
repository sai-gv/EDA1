from string import ascii_letters, digits
from itertools import product
from time import time
import os

alfabeto_base = ascii_letters + digits

def generar_combinaciones(largo_clave):
    try:
        ruta_archivo = f"combinaciones_fuerza_bruta_{largo_clave}.txt"
        with open(ruta_archivo, "w") as archivo_salida:
            print(f"Generando combinaciones de longitud {largo_clave}...")
            
            for tupla_caracteres in product(alfabeto_base, repeat=largo_clave):
                clave_candidata = "".join(tupla_caracteres)
                archivo_salida.write(clave_candidata + "\n")

        print(f"Archivo generado y cerrado: {ruta_archivo}")

    except Exception as e:
        print(f"Error durante la creación del archivo: {e}")
        return

if __name__ == "__main__":
    print("--- Algoritmo de Fuerza Bruta (Generación de Claves) ---")
    
    longitudes_a_probar = [4, 8, 10]
    tiempo_inicio = time()
    
    for longitud in longitudes_a_probar:
        generar_combinaciones(longitud)
    
    tiempo_final = time()
    print(f"Tiempo total de ejecución: {round(tiempo_final - tiempo_inicio, 6)} segundos")
