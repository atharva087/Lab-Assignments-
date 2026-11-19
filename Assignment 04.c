#include <stdio.h>

int main(void) {
    int first[2][3];
    int second[2][3];
    int sum[2][3];
    int i, j;

    printf("Enter first matrix elements:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &first[i][j]);
        }
    }

    printf("Enter second matrix elements:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &second[i][j]);
        }
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            sum[i][j] = first[i][j] + second[i][j];
        }
    }

    printf("Addition of two matrices is:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}