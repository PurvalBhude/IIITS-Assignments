Code:
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double D, root1, root2;

    printf("Enter the value of a,b,c in quadratic equation ax^2 + bx + c=0\n");

    printf("Enter a:");
    scanf("%lf",&a);

    printf("Enter b:");
    scanf("%lf",&b);

    printf("Enter c:");
    scanf("%lf",&c);

    D = b * b - 4 * a * c;
    printf("Discriment:%lf\n",D);


    if (D > 0) {
        root1 = (-b + sqrt(D)) / (2 * a);
        root2 = (-b - sqrt(D)) / (2 * a);
        printf("Root 1 = %lf\nRoot 2 = %lf\n", root1, root2);
    } else if (D == 0) {
        root1 = -b / (2 * a);
        printf("Root 1 = Root 2 = %lf\n", root1);
    } else {
        printf("NO real root exist");
    }

    return 0;
}

Input:
Enter a:1
Enter b:3
Enter c:2

Output:
Enter the value of a,b,c in quadratic equation ax^2 + bx + c=0
Enter a:1
Enter b:3
Enter c:2
Discriment:1.000000
Root 1 = -1.000000
Root 2 = -2.000000


