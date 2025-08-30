#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    // Array of input sizes
    int sizes[] = {1000, 3000, 6000, 10000, 15000, 20000, 25000};
    int total_cases = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL)); // Seed random number generator

    for (int i = 0; i < total_cases; i++) {
        int n = sizes[i];
        int *arr = malloc(n * sizeof(int));

        // Fill array with random numbers
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 10000; // limit values to 0–9999
        }

        clock_t start = clock();
        insertionSort(arr, n);
        clock_t stop = clock();

        double duration = (double)(stop - start) / CLOCKS_PER_SEC;
        printf("Size: %d -> Time: %.6f sec\n", n, duration);

        free(arr);
    }

    return 0;
}
