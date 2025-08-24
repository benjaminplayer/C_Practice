#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the temperature in celsius\n");

    float temperature;

    scanf("%f",&temperature);

    printf("%.1fC is equal to ",temperature);
    printf("%.1fF",(temperature * 9/5) +32);

    
    return 0;
}
