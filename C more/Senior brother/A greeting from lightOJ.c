#include<stdio.h>
int main()
{
    int num,sum[125],i,a,b,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        sum[i]=a+b;
    }
    for(i=0;i<n;i++)
    {
        printf("Case %d: %d\n",i+1,sum[i]);
    }
    return 0;
}
