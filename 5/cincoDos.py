import math
import multiprocessing

def ramanujan_part(start, end):
    total_sum = 0
    for k in range(start, end):
        try:
            numerator = math.factorial(4 * k) * (1103 + 26390 * k)
            denominator = (math.factorial(k) ** 4) * (396 ** (4 * k))
            total_sum += numerator / denominator
        except OverflowError:
            print(f"Overflow en k={k}, se omite este término.")
            continue
    return total_sum

def main():
    total_terms = 100_000  # Total de términos a usar (reducido para pruebas)
    num_processors = 2      # Número de procesadores

    # Calcular el rango de términos para cada proceso
    terms_per_process = total_terms // num_processors
    ranges = [(i * terms_per_process, (i + 1) * terms_per_process) for i in range(num_processors)]

    # Asegurarse de que el último proceso maneje cualquier término restante
    if total_terms % num_processors != 0:
        ranges[-1] = (ranges[-1][0], total_terms)

    # Crear un pool de procesos
    with multiprocessing.Pool(processes=num_processors) as pool:
        results = pool.starmap(ramanujan_part, ranges)

    # Sumar los resultados de todos los procesos
    total_sum = sum(results)

    # Calcular pi
    pi_estimate = (2 * math.sqrt(2) / 9801) * total_sum
    pi_estimate = 1 / pi_estimate
    print(f"Estimación de pi: {pi_estimate}")

if __name__ == "__main__":
    main()