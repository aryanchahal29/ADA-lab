#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n_values[] = {1000, 3000, 6000, 10000, 15000, 20000, 25000};
    int num_tests = sizeof(n_values) / sizeof(n_values[0]);
    srand(time(NULL));

    int runs = 3;  // number of times to run each test for averaging

    for (int i = 0; i < num_tests; i++) {
        int n = n_values[i];
        double total_time = 0;

        for (int r = 0; r < runs; r++) {
            int *arr = (int*)malloc(n * sizeof(int));

            // Generate random numbers
            for (int j = 0; j < n; j++) {
                arr[j] = rand();
            }

            clock_t start = clock();
            quickSort(arr, 0, n - 1);
            clock_t end = clock();

            total_time += (double)(end - start) / CLOCKS_PER_SEC;
            free(arr);
        }

        printf("Input size: %d, Average Time taken: %lf seconds\n", n, total_time / runs);
    }
    return 0;
}
