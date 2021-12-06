#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    long long int i,j,k,m,n,rem,div,val,previous,perfect,cp_n;
    scanf("%lld",&n);
    cp_n=n;
    for(i=0;n!=0;i++)n=n/10;

    perfect=10+(cp_n+(i-1))*9;
     printf("%lld\n",perfect);
    return 0;
}
