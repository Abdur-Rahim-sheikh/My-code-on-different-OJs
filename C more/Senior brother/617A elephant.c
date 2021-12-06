#include<stdio.h>
int main()
{
   long long int n,i,total=0,quotient;
    scanf("%lld",&n);
    for(i=5;i>=1;i--)
    {
        quotient=n/i;          //amount of i steps.
        n=n%i;                 //the left position or the left number of going home
        total=quotient+total;   //toatl amount of every steps
    }
    printf("%lld\n",total);
    return 0;
}
