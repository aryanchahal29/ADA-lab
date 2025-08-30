#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Selection Sort (slightly modified version)
void selSort(int a[], int size) {
    for (int pos = 0; pos < size - 1; pos++) {
        int smallest = pos;
        for (int nxt = pos + 1; nxt < size; nxt++) {
            if (a[nxt] < a[smallest]) {
                smallest = nxt;
            }
        }
        // swap if needed
        if (smallest != pos) {
            int hold = a[pos];
            a[pos] = a[smallest];
            a[smallest] = hold;
        }
    }
}

int main() {
    int sizes[] = {1000, 3000, 6000, 10000, 15000, 20000, 25000};
    int total = sizeof(sizes) / sizeof(sizes[0]);

    srand((unsigned int)time(NULL));  // seed for random

    for (int k = 0; k < total; k++) {
        int n = sizes[k];
        int *data = malloc(n * sizeof(int));

        // generate random numbers
        for (int idx = 0; idx < n; idx++) {
            data[idx] = rand();
        }

        // start timing
        clock_t begin = clock();
        selSort(data, n);
        clock_t finish = clock();

        double duration = (double)(finish - begin) / CLOCKS_PER_SEC;
        printf("Array size: %d --> Time: %lf sec\n", n, duration);

        free(data);
    }

    return 0;
}
