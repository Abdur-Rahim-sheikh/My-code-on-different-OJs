#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    long long int i=0,j=0,k,n,val,dont,bill,anna_portion,sum=0;
    scanf("%lld %lld",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&val);
        sum=sum+val;
        if(i==k)
            dont=val;
    }
    scanf("%lld",&bill);
    anna_portion=(sum-dont)/2;
    if(anna_portion==bill)
        printf("Bon Appetit\n");
    else
        printf("%lld\n",bill-anna_portion);


    return 0;
}
