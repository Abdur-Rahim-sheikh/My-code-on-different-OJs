///1+2+3+.....................+n=sum,sum is given i have to find the value of n.
///there is a equation also n=(sqrt(1+8n)-1)/2


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    long long int i=0,j,val,n,test,sum;
    scanf("%lld",&test);
    for(i=0;i<test;i++){
        scanf("%lld",&val);
        ///j=(sqrt(1+val)-1)/2;
        for(j=sqrt(2*val),sum=0;sum<=val;j++){
            sum=(j+1)*(j/2)+(j/2+1)*(j%2);           ///method of sun until nth value my made

               /// printf("%lld\n",sum);
        }
        printf("%lld\n",j-2);                   ///j-2 is the number on which the main sum will remain.
    }

    return 0;
}
