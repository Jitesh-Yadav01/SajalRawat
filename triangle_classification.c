#include <stdio.h>

int main() {
    float a, b, c;

    // Input the sides of the triangle
    printf("Enter three sides of the triangle: ");
    scanf("%f %f %f", &a, &b, &c);

    // Check if the given sides form a valid triangle
    if ((a + b > c) && (a + c > b) && (b + c > a)) {

        // Classification based on sides
        if (a == b && b == c)
            printf("The triangle is Equilateral.\n");
        else if (a == b || b == c || a == c)
            printf("The triangle is Isosceles.\n");
        else
            printf("The triangle is Scalene.\n");

    } else {
        printf("The given sides do not form a valid triangle.\n");
    }

    return 0;
}
