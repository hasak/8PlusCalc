#include <stdio.h>
#include <math.h>
int main()
{
    unsigned long long int a,b;
    unsigned long long int c1,c2,c3,c4;
    unsigned long long int t;
    printf("Enter two 8-byte numbers (max 18446744073709551615)\n");
    scanf("%llu %llu",&a,&b);
    printf("%llu * %llu = ",a,b);
    t=pow(10,10);
    c4=(a%t)*(b%t);
    c3=(a%t)*(b/t)+c4/t;
    c2=(a/t)*(b%t);
    c1=(a/t)*(b/t)+(c2+c3)/t;
    printf("%llu%llu%llu",c1,c2+c3,c4);
    return 0;
}
