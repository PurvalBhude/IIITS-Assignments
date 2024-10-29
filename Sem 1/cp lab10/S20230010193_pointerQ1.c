#include <stdio.h>

void printMatrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *((matrix + i * cols) + j));
        }
        printf("\n");
    }
}

void matrixAddition(int *mat1, int *mat2, int *result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *((result + i * cols) + j) = *((mat1 + i * cols) + j) + *((mat2 + i * cols) + j);
        }
    }
}

void matrixMultiplication(int *mat1, int *mat2, int *result, int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            *((result + i * cols2) + j) = 0;
            for (int k = 0; k < cols1; k++) {
                *((result + i * cols2) + j) += *((mat1 + i * cols1) + k) * *((mat2 + k * cols2) + j);
            }
        }
    }
}

void matrixTranspose(int *mat, int *result, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            *((result + j * rows) + i) = *((mat + i * cols) + j);
        }
    }
}

int matrixSearch(int *mat, int rows, int cols, int target) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (*((mat + i * cols) + j) == target) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    char c;
    int a[2][2] = {1, 1, 1, 1};
    int b[2][2] = {0, 0, 0, 0};
    int (*p)[2] = a;
    int (*q)[2] = b;

    printf("a. Addition\n");
    printf("b. Multiplication\n");
    printf("c. Transposition\n");
    printf("d. Searching an element\n");
    printf("Selection: ");
    scanf(" %c", &c);

    switch (c) {
        case 'a':
            printf("Addition:\n");
            matrixAddition((int*)p, (int*)q, (int*)a, 2, 2);
            printMatrix((int*)a, 2, 2);
            break;
        case 'b':
            printf("Multiplication:\n");
            matrixMultiplication((int*)p, (int*)q, (int*)a, 2, 2, 2, 2);
            printMatrix((int*)a, 2, 2);
            break;
        case 'c':
            printf("Transposition:\n");
            matrixTranspose((int*)p, (int*)a, 2, 2);
            printMatrix((int*)a, 2, 2);
            break;
        case 'd':
            printf("Enter the element to search: ");
            int target;
            scanf("%d", &target);
            if (matrixSearch((int*)p, 2, 2, target)) {
                printf("Element found in the matrix.\n");
            } else {
                printf("Element not found in the matrix.\n");
            }
            break;
        default:
            printf("Wrong option chosen\n");
            break;
    }

    return 0;
}
