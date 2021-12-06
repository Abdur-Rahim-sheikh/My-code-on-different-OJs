#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int j=0,hexa_bo[105][10005];
long long int fn(long long int n)
{
    if(n<6) return hexa_bo[j][n];
    else if(hexa_bo[j][n]!=0) return hexa_bo[j][n];

    hexa_bo[j][n]=(fn(n-1)+fn(n-2)+fn(n-3)+fn(n-4)+fn(n-5)+fn(n-6))%10000007;
    return hexa_bo[j][n];
}

int main()
{
    long long int i=0,k,m,n,test;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld",&hexa_bo[j][0],&hexa_bo[j][1],&hexa_bo[j][2],&hexa_bo[j][3],&hexa_bo[j][4],&hexa_bo[j][5],&n);

        printf("Case %lld: %lld\n",++i,fn(n)%10000007);

        j++;
    }
    return 0;
}
