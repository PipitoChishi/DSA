import time
import random
import matplotlib.pyplot as plt

def linear_search(arr, value):
    for i, element in enumerate(arr):
        if element == value:
            return i
    return -1

def main():
    num_experiments = int(input("Enter the number of experiments: "))
    storage = []  # Store elapsed times
    storage2 = []  # Store array sizes

    for _ in range(num_experiments):
        array_size = int(input("Enter the array size: "))
        arr = [random.randrange(1, 100) for _ in range(array_size)]  # Create random array
        print("Array elements:", arr)

        value = int(input("Enter the value to search: "))
        start_time = time.perf_counter()
        index = linear_search(arr, value)
        end_time = time.perf_counter()
        elapsed_time = end_time - start_time

        if index != -1:
            print(f"Value found at index {index}")
        else:
            print("Value not found in the array")
        print(f"Elapsed time: {elapsed_time:.6f} seconds")

        storage.append(elapsed_time)
        storage2.append(array_size)

    print("\nArray sizes:")
    for array_size in storage2:
        print(array_size)

    # Improved plot formatting
    plt.figure(figsize=(8, 6))
    plt.plot(storage2, storage, marker='o', linestyle='-', label='Elapsed Time')
    plt.xlabel("Array Size")
    plt.ylabel("Elapsed Time (seconds)")
    plt.title("Linear Search Time vs. Array Size")
    plt.grid(True)
    plt.legend()
    plt.tight_layout()  # Prevent overlapping labels
    plt.show()

if __name__ == "__main__":
    main()

