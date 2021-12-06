#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    long long int i,j,k,n,numerator,denominator,rem,arry[100];
    while(scanf("%lld %lld",&numerator,&denominator)!=EOF)
    {

       i=0;
        do
        {
            arry[i]=numerator/denominator;
            rem=numerator%denominator;
            numerator=denominator;
            denominator=rem;
            i++;

            }while(rem!=0);

        printf("[%lld;%lld",arry[0],arry[1]);
        if(i==2)
            printf("]\n");
        else{
            for(k=2;k<i;k++)
                printf(",%lld",arry[k]);

            printf("]\n");
        }
    }



    return 0;
}
