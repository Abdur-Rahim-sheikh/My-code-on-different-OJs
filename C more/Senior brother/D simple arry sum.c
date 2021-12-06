#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    int arry[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arry[i]);
    }
    for(i=0;i<n;i++)
    {
        sum=sum+arry[i];
    }
    printf("%d\n",sum);

    return 0;
}
