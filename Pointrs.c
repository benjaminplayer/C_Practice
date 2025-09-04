// I already know that this is gonna fucking suck ;-;
// Also misspeled name bc vsc thinks pointers.c is a c++ file 
#include <stdio.h>
#include <stdlib.h>
void Swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Sum(int* c, int len)
{
    int sum = 0;
    for(int i = 0; i < len; i++)
        sum +=*(c + i); // c + i -> premika pointer po array-u
    return sum;
}

void Reverse(int* arr, int len)
{
    int temp;
    for(int i = 0; i < len / 2; i++)
    {
        temp = *(arr + i); // arr[i]
        arr[i] = *(arr + (len-i-1));  // arr[i] = arr[len - i - 1]
        arr[len - i - 1] = temp;
    }

}

//chab abt wrote dis not me, me not smort enough
void ReverseFullPointer(int* arr, int len)
{
    int temp;
    int* start = arr;
    int* end = arr + len -1;

    while(start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

}

int StrLength(char* s)
{
    int i = 0;
    while(*(s + i) != '\0') i++;
    return i;
}

// yet another chat abp sollution bc idk pointer arithmetic :/
int StrLenFullPointer(char* s)
{
    char* p = s;
    while(*p != '\0') p++;
    return p - s; // p - s -> difference = length
}

void StrCopy(char* dest, char* src)
{
    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}

int Compare(char* s1, char* s2)
{

    while(*s1 && *s2 && *s1 == *s2) // *s1 => value na s1 != null | '\0' != null
    {
        s1++;
        s2++;
    }

    return *s1 - *s2;

}

int Min(int* a, int len)
{
    int *ptrlen = a +len;
    int min = *a;
    while(a < ptrlen)
    {
        if(*a < min)
            min = *a;
        a++;
    }
    return min;
}

int Max(int* a, int len)
{
    int *ptrlen = a +len;
    int max = *a;
    while(a < ptrlen)
    {
        if(*a > max)
            max = *a;
        a++;
    }
    return max;
}

int MinMax(int*a, int len, int* max)
{
    int *ptrlen = a +len;
    int mn = *a;
    int mx = *a;
    while(a < ptrlen)
    {
        if(*a < mn)
            mn = *a;
        else if(*a > mx)
            mx = *a;
        a++;
    }
    if(max != NULL) *max = mx;
    return mn;
}

void PrintArrayReverse(int* arr, int len)
{
    int* start = arr + len - 1;
    while(start >= arr)
    {
        printf("%i",*start);
        start--;
    }
}

void IncrementElements(int *arr, int len, int amount)
{
    int* end = arr + len;
    while(arr < end)
    {
        *arr += amount;
        arr++;
    }
}

void PrintArray(int a[], int len)
{
    for(int i = 0; i < len; i++)
        printf("%d ",a[i]);
}

void SwapArrayElements(int *a, int *b)
{
    if(*a == *b) return;
    *a ^= *b;
    *b = *a ^ *b;
    *a ^= *b;

}

int main()
{
    /*int a = 4, b = 1;
    printf("Before swap a: %d, b: %d",a,b);
    Swap(&a,&b);
    printf("After swap a: %d, b: %d",a,b);*/

    int arr[] = {1,2,3,4,5};
    int len = (sizeof(arr) / sizeof(arr[0]));
    /*PrintArray(arr,len);
    printf("\n");
    ReverseFullPointer(arr,len);
    PrintArray(arr,len);*/
    //char s[] = "Hello";
    //char s1[] = "Hi";
    //StrCopy(s1,s);
    //printf("The length of the string %s is: %d",s, StrLenFullPointer(s));
    //printf("Original string %s\n",s);
    //printf("Copied string %s\n",s1);
    //printf("%d",Compare(s,s1));
    //printf("min: %d; max %d",Min(arr,len), Max(arr,len));
    //PrintArrayReverse(arr,len);
    printf("Before swap \n");
    PrintArray(arr,len);
    SwapArrayElements(&arr[2], &arr[4]);
    printf("\nAfter swap \n");
    PrintArray(arr,len);
    return 0;
}