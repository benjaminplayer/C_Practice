#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int length(char a[])
{

    int i = 0;

    while(a[i] !='\0')
        i++;


    return i;
}

void ReverseInPlace(char str[], int len)
{
    printf("\n");
    printf("Original string: %s\n",str);
    //char a, b;
    for(int i = 0; i < len / 2; i++)
    {

        str[i] = str[i] ^ str[len -i - 1];
        str[len -i - 1] = str[i] ^ str[len -i - 1];
        str[i] = str[i] ^ str[len -i - 1];

    }

    printf("The reversed string is %s",str);

}

bool IsAPalindrome(char str[], int len)
{
    for(int i = 0; i < len/2; i++)
    {
        if(str[i] != str[len - i - 1])
            return false;
    }
    return true;

}

// Unfinished bc bs
void StringAnalitics(char str[], int len)
{
    int vowelsCount = 0, consonants = 0, digits = 0, spaces = 0;
    const char* vowels = "aeiouAEIOU";
    for(int i = 0; i < len; i++)
    {
        if(strchr(vowels,str[i])) vowelsCount++;
        
    }

}

char* Concat(char str1[], char str2[])
{
    int len1 = 0, len2 = 0;

    while(str1[len1] != '\0') len1++;
    while(str1[len2] != '\0') len2++;

    char* new = malloc((len1+len2+1) * sizeof(char)); // +1 -> \0
    for(int i = 0; i < len1; i++)
        new[i] = str1[i];
    for(int i = 0; i < len2; i++)
        new[len1 + i] = str2[i];
    
    new[len1+len2] = '\0';
    return new;
}

int Compare(char str1[], char str2[])
{
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    return str1[i] - str2[i];
}

/*
int FindChar(char s[], char c)
{
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] == c) return i;
    return -1;
}*/

// Vrne pointer na prvi occurance chara -> naredi substring od tam
char* FindChar(char s[], char c, int* idx) 
{
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] == c)
        {
            if(idx != NULL) *idx = i; // ce user zeli vrne tudi index
            return &s[i];
        }
    if(idx != NULL)
        *idx = -1;
    return NULL;
}

int WordCount(char s[])
{

    int words = 0;
    bool inword = false;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == ' ')
        {
            inword = false;
        }
        else if(!inword)
        {
            inword = true;
            words++;
        }
    }
    return words;

}

void ReplaceChars(char s[], char c, char c1)
{
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] == c) 
            s[i] = c1;
    
}

void Upper(char s[])
{
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
}

void Lower(char s[])
{
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
}

int main()
{

    //char a[] = "Hey";
    //printf("Length of the string %s is %d",a, length(a));
    //char str[] = "hello";
    //ReverseInPlace(str, length(str));
    /*char str[] = "";
    printf("Enter the string to check if it is a palindrome:\n");
    scanf("%s",&str);
    if(IsAPalindrome(str, length(str)))
        printf("String %s is a palindrome",str);
    else
        printf("String %s is not a palindrome",str);*/
    char s1[] = "Hello";
    Upper(s1);
    printf("%s",s1);
    Lower(s1);
    printf("%s",s1);
    return 0;
}