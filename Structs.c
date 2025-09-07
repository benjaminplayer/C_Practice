#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date
{
    unsigned short day;
    unsigned short month;
    short year;
};

struct person
{
    char name[30];
    char surname[30];
    struct date dob;
};

struct Student
{
    unsigned int rollNumber;
    char name[20];
    unsigned int grade;
};

struct complex
{
    int re; // real part
    int refrac; // real denuminator
    int im; // imaginary part
    int imfrac; // imaginary denuminator
};

struct book
{
    char title[30];
    char author[50];
    unsigned short price;
};


struct complex complexAdd(struct complex z1, struct complex z2)
{
    struct complex result;
    result.re = z1.re + z2.re;
    result.im = z1.im + z2.im;
    return result;
}

struct complex complexSubtract(struct complex z1, struct complex z2)
{
    struct complex result;
    result.re = z1.re - z2.re;
    result.im = z1.im - z2.im;
    return result;
}

struct complex complexMult(struct complex z1, struct complex z2)
{
    struct complex result;
    result.re = z1.re * z2.re - z1.im * z2.im;
    result.im = z1.re * z2.im + z1.im * z2.re;
    return result;
}

struct complex conjugate(struct complex z1)
{
    z1.im = -z1.im;
    return z1;
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

struct complex simplify(struct complex z)
{
    struct complex f;
    int rgcd = gcd(z.re, z.refrac);
    int igcd = gcd(z.im, z.imfrac);

    f.re = z.re / rgcd;
    f.refrac = z.refrac / rgcd;
    f.im = z.im / igcd;
    f.imfrac = z.imfrac / igcd;
    return f;
}

//TODO Poenostavi imenovalc
struct complex complexDiv(struct complex z1, struct complex z2)
{
    struct complex result;
    //result = complexMult(z1,conjugate(z2)) / ((z2.re * z2.re)+(z2.im*z2.im));
    if(z2.re == 0 && z2.im == 0)
    {
        printf("Cannot divide by 0");
        exit(1);
    }

    result.refrac = z2.re*z2.re + z2.im * z2.im; // calc the fraction
    result.imfrac = result.refrac;
    result.re = z1.re * z2.re + z1.im * z2.im;
    result.im = z1.im * z2.re - z1.re * z2.im; 
    return simplify(result);
}

struct complex printComplex(struct complex z)
{
    char operator = (z.im > 0)? '+':'-';
    if((z.refrac != 0 && z.imfrac != 0) && !(z.refrac == 1 && z.imfrac == 1)) // both frac and not x/1
    {
        if(z.refrac == 1)
            printf("%d %c %d/%di",z.re,operator,abs(z.im),z.imfrac);
        else if(z.imfrac == 1)
            printf("%d/%d %c %di",z.re,z.refrac,operator,abs(z.im));
        else
            printf("%d/%d %c %d/%di",z.re,z.refrac,operator,abs(z.im),z.imfrac);
    } 
    else
    {
        if(z.refrac != 0)
            printf("%d/%d %c %di",z.re,z.refrac,operator,abs(z.im));
        else if(z.imfrac != 0)
            printf("%d %c %d/%di",z.re,operator,abs(z.im),z.imfrac);
        else
            printf("%d %c %di",z.re,operator,abs(z.im)); // general output if a num is not a fraction
    } 
}

void findHighestAndLowestGrades(int len, struct Student *arr)
{
    unsigned int min = arr[0].grade, idxMin = 0;
    unsigned int max = arr[0].grade, idxMax = 0;
    for(int i = 1; i < len; i++)
    {
        if(arr[i].grade < min)
        {
            min = arr[i].grade;
            idxMin = i;
        }
        else if(arr[i].grade > max)
        {
            max = arr[i].grade;
            idxMax = i;
        }    
    }

    printf("Min grade: Name: %s, grade:%d\n",arr[idxMin].name,min);
    printf("Max grade: Name: %s, grade:%d\n",arr[idxMax].name,max);

}

double avg(int len, struct Student *arr)
{
    unsigned int sum = 0;

    for(int i = 0; i < len; i++)
        sum += arr[i].grade;
    
    return sum / (double)len;
}

int compare(char s1[], char s2[])
{   
    int i = 0;
    while(s1[i] !='\0' && s2[i] !='\0')
    {
        if(s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}

void sort(struct Student *arr, int len)
{
    for(int i = 1; i < len; i++)
    {
        struct Student key = arr[i];
        int j = i - 1;
        while(j >= 0 && compare(arr[j].name, key.name) > 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

}

void printStudentsInfo(struct Student *arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("rollNum: %d; name: %s; grade: %d\n",arr[i].rollNumber,arr[i].name,arr[i].grade);
    }

}

void searchBookByTitle(struct book *lib, int len, char title[])
{
    for(int i = 0; i < len; i++)
    {
        if(strcmp(lib[i].title, title) == 0)
        {
            printf("Book: %s\nAuthor: %s\nPrice: %hu\n",
                   lib[i].title, lib[i].author, lib[i].price);
            return;
        }
    }
    printf("Book not found!\n");
}

void printDate(struct date d)
{
    printf("%d/%d/%d",d.day,d.month,d.year);
}

void printPerson(struct person p)
{
    printf("Name: %s, Surname: %s, Date of birth: %d/%d/%d",p.name, p.surname,p.dob.day,p.dob.month,p.dob.year);
}

void changeName(struct person *p, char name[])
{
    strcpy(p->name,name);
}

int main()
{
/*
    struct Student s1 = {12,"Tony",5};
    struct Student s2 = {13,"Pinki",2};
    struct Student s3 = {14,"Palinko",3};
    struct Student s4 = {15,"Dera",1};
    struct Student s5 = {16,"Sda",2};

    struct Student students[5];
    students[0] = s1;
    students[1] = s2;
    students[2] = s3;
    students[3] = s4;
    students[4] = s5;

    //printf("rollNum: %d; name: %s; grade:%d",s1.rollNumber,s1.name,s1.grade);
    //findHighestAndLowestGrades(5,students);
    //printf("%f",avg(5,students));

    //printf("%d",compare("a","b"));
    /*printf("Before sort:\n");
    printStudentsInfo(students, 5);
    sort(students,5);
    printf("After sort:\n");
    printStudentsInfo(students, 5);

    students[0].grade = 2;
    strcpy(students[0].name, "Lola");*/

    /*struct complex z1 = {20,-4};
    struct complex z2 = {3,0,1};
    struct complex z3 = {2,4,0,3};
    struct complex z4 = {4,2,3,0};
    printf("Complex div:\n");
    //struct complex z3 = complexDiv(z1,z2);
    printComplex(z2);*/

    /*struct book library[4];
    strcpy(library[0].title, "The C Programming Language");
    strcpy(library[0].author, "Kernighan & Ritchie");
    library[0].price = 50;

    strcpy(library[1].title, "Clean Code");
    strcpy(library[1].author, "Robert C. Martin");
    library[1].price = 40;

    strcpy(library[2].title, "Na Klancu");
    strcpy(library[2].author, "Ivan");
    library[2].price = 10;

    strcpy(library[3].title, "The Silver Eyes");
    strcpy(library[3].author, "Scott Cawthon");
    library[3].price = 15;

    printf("Enter the books title\n");
    char name[] = "";
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0'; // -> ker fgets doda \n na konec line strcspm(name,\n) dobi index od \n in ga zamenja z \0
    printf("Name:%s\n",name);
    searchBookByTitle(library,4,name);*/
    struct date d = {12,12,2000};
    struct person p = {"Test","Sest",d};

    printPerson(p);
}