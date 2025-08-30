#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to search element linearly
int searchLinear(int *a, int size, int element) {
    int pos = -1;
    for (int idx = 0; idx < size; idx++) {
        if (a[idx] == element) {
            pos = idx;
            break;  // exit loop as soon as found
        }
    }
    return pos;
}

int main() {
    int size, element;

    printf("How many numbers you want to store? ");
    scanf("%d", &size);

    // Dynamic memory allocation
    int *data = malloc(size * sizeof(int));
    if (!data) {
        fprintf(stderr, "Error: Memory not allocated!\n");
        return 1;
    }

    // Fill array with random values
    srand(time(NULL));
    for (int k = 0; k < size; k++) {
        data[k] = rand() % 100000;
    }

    // choose last element for searching (worst case)
    element = data[size - 1];

    clock_t begin = clock();
    for (int trial = 0; trial < 1000; trial++) {
        int ans = searchLinear(data, size, element);
        (void)ans; // prevent unused variable warning
    }
    clock_t finish = clock();

    // Calculate average time
    double avg_time = ((double)(finish - begin) / CLOCKS_PER_SEC) / 1000.0;

    printf("Searching for: %d\n", element);
    printf("Average time for n=%d → %lf seconds (1000 trials)\n", size, avg_time);

    free(data);
    return 0;
}
