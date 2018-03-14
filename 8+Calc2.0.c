/*
8+ Calculator® v2.0

This simple program multiplies two 8-byte numbers into much bigger one.
It uses simple hand-calculating algorithm.

Free for all, keep sharing*

Change log: Same algorithm but much more optimized (skipped few intermediate steps)

*After professor grade it :)

Himzo Hasak – Mar 2018
*/
#include <stdio.h>
int main()
{
    unsigned long long int a,b;     // These two are only long long variables used to store number (2^64-1 max)
    unsigned long long int t;       // One temporary variable
    unsigned short int result[42];  // Result array
    unsigned short int i,j,la,lb;   // Spam variables
    printf("Enter two 8-byte numbers (max 18446744073709551615)\n");
    scanf("%llu %llu",&a,&b);
    printf("%llu * %llu = ",a,b);
    la=floor(log10(a))+1;           // Increased speed with this simple digit counter (instead of O(n) now is O(logn))
    lb=floor(log10(b))+1;
    for(i=0;i<la+lb;i++)            // Setting values to 0 for later incrementing
        result[i]=0;
    for(i=0;i<la;i++) {             // Now here everything gets calculated. Many steps are skipped in this way
        t=b;                        // As we have to traverse through b several times, we have to use temp
        for(j=0;j<lb;j++) {
            result[i+j]+=(a%10)*(t%10);    // Multiply last two digits and put in array with respect to shift
            result[i+j+1]+=result[i+j]/10; // If number is greater than 10, hold last digit and move rest to next element
            result[i+j]%=10;t/=10;         // Cut last calculated digit
        }
        a/=10;                      // Cut also from a when j loop finishes
    }
    for(i=0;i<la+lb-1;i++)          // Print everything without spaces in reverse order so it looks like a number
        printf("%hu",result[la+lb-2-i]);
    return 0;
}
