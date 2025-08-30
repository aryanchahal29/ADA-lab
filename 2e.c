#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Optimized Bubble Sort
void bubble_sort(int a[], int n) {
    for (int pass = 0; pass < n - 1; pass++) {
        int didSwap = 0;
        for (int k = 0; k < n - pass - 1; k++) {
            if (a[k] > a[k + 1]) {
                // swap elements
                int hold = a[k];
                a[k] = a[k + 1];
                a[k + 1] = hold;
                didSwap = 1;
            }
        }
        // if no swap, array already sorted
        if (didSwap == 0) {
            break;
        }
    }
}

int main() {
    int sizes[] = {1000, 3000, 6000, 10000, 15000, 20000, 25000};
    int total_cases = sizeof(sizes) / sizeof(sizes[0]);

    srand((unsigned int)time(NULL));

    for (int t = 0; t < total_cases; t++) {
        int n = sizes[t];
        int *data = malloc(n * sizeof(int));

        // generating random data
        for (int idx = 0; idx < n; idx++) {
            data[idx] = rand();
        }

        clock_t begin = clock();
        bubble_sort(data, n);
        clock_t finish = clock();

        double elapsed = (double)(finish - begin) / CLOCKS_PER_SEC;
        printf("Array length: %d -> Time: %lf seconds\n", n, elapsed);

        free(data);
    }

    return 0;
}
