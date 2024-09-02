import time
import random
import pandas as pd
import matplotlib.pyplot as plt

def linear_search(arr, value):
    for i, element in enumerate(arr):
        if element == value:
            return i
    return -1

def main(arr=None):
    if arr is None:
        arr = []
    num_experiments = int(input("Enter the number of experiments: "))
    storage = []
    storage2 = []
    for _ in range(num_experiments):
        array_size = int(input("Enter the array size: "))
        for _ in range(array_size):
            random_value = random.randint(1, 100)
            arr.append(random_value)
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
        print(f"Elapsed time: {elapsed_time} seconds")
        storage.append(elapsed_time)
        storage2.append(len(arr))
    print("\nArray sizes:")
    for array_size in storage2:
        print(array_size)
    plt.plot(storage2, storage, marker='o')
    plt.xlabel("Array Size")
    plt.ylabel("Elapsed Time (seconds)")
    plt.title("Linear Search Time vs. Array Size")
    plt.grid(True)
    plt.show()

if __name__ == "_main_":
    main()


