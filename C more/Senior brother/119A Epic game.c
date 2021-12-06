#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,n,rem,cpN,cpA,cpB,Lb,La,total;
    scanf("%d %d %d",&a,&b,&n);
    La=n;
    cpA=a;
    cpB=b;
    for(;;)
    {

        for(rem=1;rem!=0;)
        {
            rem=n%a;
            n=a;
            a=rem;
        }
        Lb=La-n;
        if(Lb<0)
        {
            printf("1\n");
            return 0;
        }
        if(Lb==0)
        {
            printf("0\n");
            return 0;
        }
        total=Lb+cpB;
        n=(total+abs(Lb-cpB))/2;
        b=total-n;

        for(rem=1;rem!=0;)
        {
            rem=n%b;
            n=b;
            b=rem;
        }
        La=Lb-n;
        if(La<0)
        {
            printf("0\n");
            return 0;
        }
        if(La==0)
        {
            printf("1\n");
            return 0;
        }
        total=La+cpA;
        n=(total+abs(La-cpA))/2;
        a=total-n;
    }
    return 0;
}
