#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure for dynamic arrays
struct MyArray {
    int total_size;
    int used_size;
    int *ptr; // Pointer to the dynamically allocated array
};

// Function to create an array dynamically
void createArray(struct MyArray *a, int tsize, int usize) {
    a->total_size = tsize; // Set the total size
    a->used_size = usize;  // Set the initial used size

    // Allocate memory for the array using malloc
    a->ptr = (int *)malloc(tsize * sizeof(int));
    if (a->ptr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }
}

int main() {
    struct MyArray Marks;

    createArray(&Marks, 100, 20);
     
    free(Marks.ptr);

    return 0;
}