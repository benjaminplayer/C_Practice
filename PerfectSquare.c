#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if(n < 0) {
        printf("Negative numbers cannot be perfect squares.\n");
        return 0;
    }

    double root = sqrt(n);       // Get the square root
    int root_int = (int)root;    // Convert to integer

    if(root_int * root_int == n)
        printf("%d is a perfect square.\n", n);
    else
        printf("%d is not a perfect square.\n", n);

    return 0;

}