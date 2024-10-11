import multiprocessing
import random

def monte_carlo_pi(samples):
    count_inside_circle = 0
    for _ in range(samples):
        x, y = random.random(), random.random()
        if x**2 + y**2 <= 1:
            count_inside_circle += 1
    return count_inside_circle

def calculate_pi(total_samples):
    # Número de procesos
    num_processes = multiprocessing.cpu_count()  # O puedes fijarlo a 3
    samples_per_process = total_samples // num_processes

    with multiprocessing.Pool(processes=num_processes) as pool:
        results = pool.map(monte_carlo_pi, [samples_per_process] * num_processes)

    total_inside_circle = sum(results)
    pi_estimate = (total_inside_circle / total_samples) * 4
    return pi_estimate

if __name__ == '__main__':
    total_samples = 1_000_000
    pi_value = calculate_pi(total_samples)
    print(f"Estimación de π con {total_samples} muestras: {pi_value}")