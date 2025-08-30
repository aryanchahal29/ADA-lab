#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void addMatrix(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void subMatrix(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Print matrix
void printMatrix(int n, int M[n][n]) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            printf("%5d ", M[i][j]);
        printf("\n");
    }
}

// Strassen’s algorithm (recursive)
void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n/2;
    int A11[k][k], A12[k][k], A21[k][k], A22[k][k];
    int B11[k][k], B12[k][k], B21[k][k], B22[k][k];
    int C11[k][k], C12[k][k], C21[k][k], C22[k][k];
    int M1[k][k], M2[k][k], M3[k][k], M4[k][k], M5[k][k], M6[k][k], M7[k][k];
    int temp1[k][k], temp2[k][k];

    // Divide A and B into 4 sub-matrices
    for (int i=0; i<k; i++) {
        for (int j=0; j<k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    addMatrix(k, A11, A22, temp1);
    addMatrix(k, B11, B22, temp2);
    strassen(k, temp1, temp2, M1);

    // M2 = (A21 + A22) * B11
    addMatrix(k, A21, A22, temp1);
    strassen(k, temp1, B11, M2);

    // M3 = A11 * (B12 - B22)
    subMatrix(k, B12, B22, temp2);
    strassen(k, A11, temp2, M3);

    // M4 = A22 * (B21 - B11)
    subMatrix(k, B21, B11, temp2);
    strassen(k, A22, temp2, M4);

    // M5 = (A11 + A12) * B22
    addMatrix(k, A11, A12, temp1);
    strassen(k, temp1, B22, M5);

    // M6 = (A21 - A11) * (B11 + B12)
    subMatrix(k, A21, A11, temp1);
    addMatrix(k, B11, B12, temp2);
    strassen(k, temp1, temp2, M6);

    // M7 = (A12 - A22) * (B21 + B22)
    subMatrix(k, A12, A22, temp1);
    addMatrix(k, B21, B22, temp2);
    strassen(k, temp1, temp2, M7);

    // C11 = M1 + M4 - M5 + M7
    for (int i=0; i<k; i++)
        for (int j=0; j<k; j++)
            C11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];

    // C12 = M3 + M5
    for (int i=0; i<k; i++)
        for (int j=0; j<k; j++)
            C12[i][j] = M3[i][j] + M5[i][j];

    // C21 = M2 + M4
    for (int i=0; i<k; i++)
        for (int j=0; j<k; j++)
            C21[i][j] = M2[i][j] + M4[i][j];

    // C22 = M1 - M2 + M3 + M6
    for (int i=0; i<k; i++)
        for (int j=0; j<k; j++)
            C22[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];

    // Combine into final matrix C
    for (int i=0; i<k; i++) {
        for (int j=0; j<k; j++) {
            C[i][j] = C11[i][j];
            C[i][j+k] = C12[i][j];
            C[i+k][j] = C21[i][j];
            C[i+k][j+k] = C22[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter size of matrix (power of 2): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter elements of Matrix A:\n");
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            scanf("%d", &B[i][j]);

    // Multiply
    strassen(n, A, B, C);

    printf("\nResultant Matrix C (A x B):\n");
    printMatrix(n, C);

    return 0;
}
