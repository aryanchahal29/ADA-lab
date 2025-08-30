#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fill array with random integers
void fillArray(int *a, int len) {
    for (int k = 0; k < len; k++) {
        a[k] = rand() % 100000;
    }
}

// Bubble sort (slightly modified style)
void sortBubble(int *a, int len) {
    for (int p = 1; p < len; p++) {
        for (int q = 0; q < len - p; q++) {
            if (a[q] > a[q + 1]) {
                int t = a[q];
                a[q] = a[q + 1];
                a[q + 1] = t;
            }
        }
    }
}

// Binary search implementation
int binSearch(int *a, int len, int key) {
    int low = 0, high = len - 1;
    while (low <= high) {
        int mid = (low + high) / 2; // slightly different mid calculation
        if (a[mid] == key) {
            return mid;
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int testSizes[] = {10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000};
    int totalCases = sizeof(testSizes) / sizeof(testSizes[0]);

    printf("n,TimeTakenSeconds\n");

    for (int idx = 0; idx < totalCases; idx++) {
        int n = testSizes[idx];
        int *arr = malloc(n * sizeof(int));
        if (!arr) {
            fprintf(stderr, "Allocation failed for size %d\n", n);
            continue;
        }

        fillArray(arr, n);
        sortBubble(arr, n);

        int searchKey = arr[n - 1];  // last element → worst case

        clock_t begin = clock();
        for (int rep = 0; rep < 10000000; rep++) {
            int found = binSearch(arr, n, searchKey);
            (void)found; // avoid unused warning
        }
        clock_t finish = clock();

        double avgTime = ((double)(finish - begin)) / CLOCKS_PER_SEC / 10000000.0;
        printf("%d,%.8f\n", n, avgTime);

        free(arr);
    }

    return 0;
}
