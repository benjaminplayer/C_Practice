#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
bool isPrime(int num)
{
    for(int i = 3; i * i < num; i += 2)
        if(num % i == 0) return false;
    return true;
}

int factorial(int a)
{
    if(a == 0) return 1;
    else return a * factorial(a-1);
}

int gcd(int a, int b)
{
    while (b !=0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}

int main()
{
    int a,b;
    
    printf("Enter a number \n");
    scanf("%d",&a);
    printf("Enter a second number \n");
    scanf("%d",&b);
    //(isPrime(a)) ? printf("%d is a prime",a) : ("%d is not a prime",a);
    //printf("%d",factorial(a));
    printf("gcd: %d",gcd(a,b));

    return 0;
}