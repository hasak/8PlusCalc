/*

8+ Calculator® v1.0

This simple program multiplies two 8-byte numbers into much bigger one.
It uses simple hand-calculating algorithm.

Free for all, keep sharing*

*After professor grade it :)

Himzo Hasak – Mar 2018

*/

#include<stdio.h>
#define N 21                         // Why 21? Because largest possible long long number has 20 digits (in decimal system). One extra from me
int main()
{
    unsigned long long int a;                                        // These two are only long long variables used to store number (2^64-1 max)
    unsigned long long int b;
    unsigned short int i,j,la,lb,t;                                  // Necessary spam variables, la & lb are number of digits in both numbers
    unsigned short int arra[N],arrb[N],mat[N][N],res[2*N];           // Arrays for slicing numbers and matrix to multiply every digit

    printf("Enter two 8-byte numbers (max 18446744073709551615)\n"); // Input statements
    scanf("%llu %llu",&a,&b);
    printf("\n%llu * %llu = ",a,b);                                  // Output statement. Calculated value will be added later

    i=0;
    while(a!=0){                     // These two whiles slice number in array and calculate no of digits in numbers (lazy for functions)
        arra[i]=a%10;
        a/=10;
        i++;
    }
    la=i;

    i=0;
    while(b!=0){
        arrb[i]=b%10;
        b/=10;
        i++;
    }
    lb=i;

    for(i=0;i<la/2;i++)              // Two fors for changing order of elements in array because they were inserted in opposite direction
    {
        t=arra[la-1-i];
        arra[la-1-i]=arra[i];
        arra[i]=t;
    }

    for(i=0;i<lb/2;i++)
    {
        t=arrb[lb-1-i];
        arrb[lb-1-i]=arrb[i];
        arrb[i]=t;
    }

    for(i=0;i<la;i++)                // From now coding starts. Here we are multiplying every digit from one number with every digit from second one
    {                                // This is based on hand calculating algorithm for multiplying that we learned in elementary school
        for(j=0;j<lb;j++)            // Thanks OŠ "Huso Hodžic" Tešanj (insert reference)
        {
            mat[i][j]=arra[i]*arrb[j];
        }
    }

    for(i=0;i<2*N;i++)               // Making zero valued array for result
    {
        res[i]=0;
    }

    for(i=0;i<la;i++)                // Here is little bit tricky. Now we are summing rows with shifting (recall hand multiplying) and placing values in array
    {
        for(j=0;j<lb;j++)
        {
            res[j+i]+=mat[i][j];
        }
    }
                                     // This commented section is for debugging. Print matrix and result array etc
    /*
    for(i=0;i<la;i++)
    {
        for(j=0;j<lb;j++)
        {
            printf("%hu ",mat[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=0;i<2*N;i++)
    {
        printf("%hu ",res[i]);
    }

    printf("\n");
    */
    for(i=la+lb-2;i>0;i--)           // Firstly we just add every value and put into array without caring about carrying digits
    {                                // Here we do just that. Every element is just is LSD and rest is added to left one
        res[i-1]+=res[i]/10;         // In this case, leftmost element will consist of multiple digits, but nevermind, we are printing without spaces
        res[i]%=10;                  // so it wont be noticed
    }

    for(i=0;i<la+lb-1;i++)
    {
        printf("%hu",res[i]);        // Printing number that looks like it is number and not array element
    }

    printf("\n");                    // Null comment

    return 0;
}
