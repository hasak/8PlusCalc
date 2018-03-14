#include<stdio.h>
unsigned long long int expp(int a, int b){
    int i;
    unsigned long long int r=1;
    for(i=0;i<b;i++)
        r*=a;
    return r;
}
int digits(unsigned long long int a){
    int c=0;
    while(a!=0){
        a/=10;
        c++;
    }
    return c;
}
int main()
{
    int ulli=sizeof(long long int);
    unsigned long long int a,b,t1,t2,t3,t4,div;
    printf("\nWe can multiply %d-byte number maximum on this system.\nEnter two numbers not bigger than 2^%d-1\n\n",ulli,ulli*8);
    scanf("%llu %llu",&a,&b);
    div=expp(10,digits(expp(2,ulli*8-1))/2+1);
    t4=(a%div)*(b%div);
    t3=(a%div)*(b/div);
    t2=(a/div)*(b%div);
    t1=(a/div)*(b/div)+t3/div+t2/div;
    t2%=div;t3%=div;t2+=t3;t1+=t2/div;t2%=div;
    t2+=t4/div;t4%=div;t1+=t2/div;t2%=div;
    printf("\n\nResult: %llu%llu%llu\n",t1,t2,t4);
    return 0;
}
