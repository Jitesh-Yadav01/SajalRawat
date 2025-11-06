#include <stdio.h>

int main() {
    int marks[100];
    int n, i;
    int max, min;
    float sum = 0, avg;
    int countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input marks
    printf("Enter marks of %d students (out of 100):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
    }

    // Initialize max and min
    max = min = marks[0];

    // Analyze marks
    for (i = 0; i < n; i++) {
        sum += marks[i];

        if (marks[i] > max)
            max = marks[i];
        if (marks[i] < min)
            min = marks[i];

        // Grade distribution
        if (marks[i] >= 90)
            countA++;
        else if (marks[i] >= 75)
            countB++;
        else if (marks[i] >= 60)
            countC++;
        else if (marks[i] >= 40)
            countD++;
        else
            countF++;
    }

    // Calculate average
    avg = sum / n;

    // Display results
    printf("\n===== Problem Solving Techniques - Marks Analysis =====\n");
    printf("Total Students: %d\n", n);
    printf("Average Marks: %.2f\n", avg);
    printf("Highest Marks: %d\n", max);
    printf("Lowest Marks: %d\n", min);

    printf("\nGrade Distribution:\n");
    printf("A (90-100): %d students\n", countA);
    printf("B (75-89):  %d students\n", countB);
    printf("C (60-74):  %d students\n", countC);
    printf("D (40-59):  %d students\n", countD);
    printf("F (<40):    %d students\n", countF);

    return 0;
}
