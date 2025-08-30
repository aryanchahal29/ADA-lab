#include <stdio.h>
#include <stdlib.h>

// Function to create a dynamic 2D matrix
int** createMatrix(int n) {
    int** mat = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = malloc(n * sizeof(int));
    }
    return mat;
}

// Free memory of a 2D matrix
void destroyMatrix(int** mat, int n) {
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

// Add two matrices into a third
void matrixAdd(int** X, int** Y, int** Z, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            Z[r][c] = X[r][c] + Y[r][c];
        }
    }
}

// Recursive matrix multiplication (divide & conquer)
void divideMultiply(int** A, int** B, int** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int half = n / 2;

    // Submatrices
    int **A11 = createMatrix(half), **A12 = createMatrix(half),
        **A21 = createMatrix(half), **A22 = createMatrix(half);
    int **B11 = createMatrix(half), **B12 = createMatrix(half),
        **B21 = createMatrix(half), **B22 = createMatrix(half);
    int **C11 = createMatrix(half), **C12 = createMatrix(half),
        **C21 = createMatrix(half), **C22 = createMatrix(half);

    int **P1 = createMatrix(half), **P2 = createMatrix(half),
        **P3 = createMatrix(half), **P4 = createMatrix(half),
        **P5 = createMatrix(half), **P6 = createMatrix(half),
        **P7 = createMatrix(half), **P8 = createMatrix(half);

    // Divide A and B
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // Recursive calls
    divideMultiply(A11, B11, P1, half);
    divideMultiply(A12, B21, P2, half);
    divideMultiply(A11, B12, P3, half);
    divideMultiply(A12, B22, P4, half);
    divideMultiply(A21, B11, P5, half);
    divideMultiply(A22, B21, P6, half);
    divideMultiply(A21, B12, P7, half);
    divideMultiply(A22, B22, P8, half);

    // Merge results
    matrixAdd(P1, P2, C11, half);
    matrixAdd(P3, P4, C12, half);
    matrixAdd(P5, P6, C21, half);
    matrixAdd(P7, P8, C22, half);

    // Reconstruct final C
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }

    // Free allocated submatrices
    destroyMatrix(A11, half); destroyMatrix(A12, half);
    destroyMatrix(A21, half); destroyMatrix(A22, half);
    destroyMatrix(B11, half); destroyMatrix(B12, half);
    destroyMatrix(B21, half); destroyMatrix(B22, half);

    destroyMatrix(C11, half); destroyMatrix(C12, half);
    destroyMatrix(C21, half); destroyMatrix(C22, half);

    destroyMatrix(P1, half); destroyMatrix(P2, half);
    destroyMatrix(P3, half); destroyMatrix(P4, half);
    destroyMatrix(P5, half); destroyMatrix(P6, half);
    destroyMatrix(P7, half); destroyMatrix(P8, half);
}

// Print matrix
void showMatrix(int** mat, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            printf("%4d ", mat[r][c]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4; // Must be power of 2
    int** A = createMatrix(n);
    int** B = createMatrix(n);
    int** C = createMatrix(n);

    printf("Enter elements of 4x4 Matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of 4x4 Matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("B[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

    // Perform multiplication
    divideMultiply(A, B, C, n);

    printf("\nResult Matrix (A x B):\n");
    showMatrix(C, n);

    destroyMatrix(A, n);
    destroyMatrix(B, n);
    destroyMatrix(C, n);

    return 0;
}
