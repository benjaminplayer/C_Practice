#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void largestSmallestElement(int arr[], int len)
{

    int max = arr[0], min = arr[0];

    for (int i = 0; i < len; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if (arr[i] < min)
            min = arr[i];
    }

    printf("Smallest number: %d\n", min);
    printf("Largest number: %d\n", max);
}

void sumAndAvg(int arr[], int len)
{
    int sum = 0;
    double avg;
    for (int i = 0; i < len; i++)
        sum += arr[i];
    avg = (double)sum / len;

    printf("Sum of all elements: %d\n", sum);
    printf("Avg of all the elements: %lf \n", avg);
}

void reverseArray(int arr[], int len)
{
    printf("%d \n",len);

    printf("Array before reverse:\n");

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    int a, b;
    for (int i = 0; i < len / 2; i++) //could have used temp to swp xD
    {
        a = arr[i];
        b = arr[len - i - 1];
        arr[i] = b;
        arr[len - i - 1] = a;
    }

    printf("Array after reverse:\n");

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void evenAndOdd(int arr[], int len)
{
    int even = 0, odd = 0;

    for(int i = 0; i < len; i++)
        ((arr[i] & 1) == 0) ? even++ : odd++;
    printf("Even numbers in array: %d\n",even);
    printf("Odd numbers in array: %d\n",odd);
}

int* merge(int arr1[], int len1, int arr2[], int len2)
{
    int arrlen = len1 + len2;
    int* a = malloc(arrlen * sizeof(int)); // *sizeof int -> prepreci under-allocation

    if (a == NULL) {  // always check malloc success
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for(int i = 0; i < len1; i++)
    {
       a[i] = arr1[i];
    }
    for(int i = 0; i < len2; i++)
        a[len1 + i] = arr2[i];
    return a;
}

void secondLargestElement(int arr[], int len)
{

    int max = INT_MIN, second = INT_MIN;

    for(int i = 0; i < len; i++)
    {
        if(max < arr[i])
        {
            second = max;
            max = arr[i];
        }
        else if(arr[i] > second && arr[i] < max)
        {
            second = arr[i];
        }
    }

    printf("Largest element is %d\n",max);
    printf("Second largest element is %d\n",second);

}

void sortAsc(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int* removeDuplicates(int arr[], int len, int* newSize)
{
    int length = len* sizeof(int);
    int* a = malloc(length);
    if(a == NULL)
    {
        exit(1);
    }

    int k = 0; // number of unique elements
    for (int i = 0; i < len; i++) {
        bool exists = false;
        for (int j = 0; j < k; j++) {
            if (arr[i] == a[j]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            a[k] = arr[i];
            k++;
        }
    }

    *newSize = k;

    return a;

}
/* TODO: FIX SHIFTING
int* shiftElements(int arr[], int len, int val)
{
    if(abs(val) > len - 1)
    {
        printf("Incorrect value for shift: %d",val);
        exit(1);
    }

    int* a = malloc(len * sizeof(int));

    if(val > 0)
    {
        int k = val;
        for(int i = 0; i < len; i++, k++)
        {
            if(k <= len-1)
                a[i] = arr[k];
            else
            {
                k = 0;
            }
        }
    }

    return a;
}*/

int main()
{
    //int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arr[] = {10,2,6,2};
    int len = (sizeof(arr) / sizeof(arr[0])); // (sizeof(arr)/sizeof(arr[0])) => dobi size arraya, ker sizeof(arr[]) vrne veliksot pointerja na mem loc
    /*int* ceanedUpPtrLen;
    largestSmallestElement(arr, len);
    sumAndAvg(arr, len);
    reverseArray(arr, len);
    evenAndOdd(arr,len);
    int arr1[] = {8,9};
    int len1 = (sizeof(arr1) / sizeof(arr1[0]));
    int* arr3 = merge(arr, len, arr1, len1);
    printArray(arr3, len + len1);
    free(arr3);*/
    //secondLargestElement(arr,len);
    /*sortAsc(arr, len);
    printArray(arr, len);

    int size;

    int* cleanedUp = removeDuplicates(arr,len, &size);
    printArray(cleanedUp, size);
    free(cleanedUp);*/

    printArray(arr, len);

    /*int* shifted = shiftElements(arr, len, 2);

    printArray(shifted, len);
    free(shifted);*/

    return 0;
}