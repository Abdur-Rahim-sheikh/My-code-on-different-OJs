#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    long long int i=0,j,k,n,val,sum=0;
    scanf("%lld %lld",&n,&k);
    for(i=0;i<n;i++){
        scanf("%lld",&val);
        sum=sum+val;
        if(val<j || i==0)
            j=val;
    }
    k=k-sum;
    printf("%lld\n",n+k/j);



    return 0;
}
