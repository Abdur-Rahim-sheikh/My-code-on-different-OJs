#include<stdio.h>
int main()
{
    long long int n,nth,p,mul=0,mul1;
    scanf("%lld",&p);
    for(n=1 ; ; )
    {
        mul1=mul;
        mul=mul+n*5;
        if(mul>=p)
            break;
        else
        {
            n=n*2;
        }
    }
    nth=p-mul1;


        if(nth>=1 && nth<=n)
        printf("Sheldon\n");
       else if(nth>n && nth<=2*n)
        printf("Leonard\n");
        else if(nth>2*n && nth<=3*n)
            printf("Penny\n");
        else if(nth>3*n && nth<=4*n)
            printf("Rajesh\n");
        else
            printf("Howard\n");
        return 0;
}
