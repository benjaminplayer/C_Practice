#include <stdio.h>
#include <stdlib.h>

int main()
{
    const double PI = 3.14159265;
    printf("Enter the radius of the circle \n");
    double r;

    scanf("%lf",&r);
    printf("The radius of the circle is %.4lf", (2*PI*r));

    return 0;
}
