#include<stdio.h>
int main()
{
    long int i,n,sum1=0,sum2=0,sum3=0,tem=0;
    scanf("%d",&n);
    for(i=1;tem<n;i++)
    {
        sum3=sum2+(sum1+i);
        sum1=sum1+i;
        sum2=sum2+sum1;
        tem=sum2+sum1+i;
    }
    printf("%d\n",i-1);
    return 0;
}
