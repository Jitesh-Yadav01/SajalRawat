#include <stdio.h>

int main() {
    int i, j, space, rows;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
        // Print spaces
        for (space = i; space < rows; space++) {
            printf("  ");  // Two spaces for alignment
        }

        // Print stars
        for (j = 1; j <= i; j++) {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}
