#include<stdio.h>

int  main()
{
    long long int a,b,s1,s2;

    ///int cannot save value bigger than ~ 10^9 ok
    scanf("%lld %lld",&a,&b);
    a= a-1;
    s2=(b*(b+1))/2;
    s1 = (a*(a+1))/2;
    printf("%lld",s2-s1);
    return 0;

}
