#include<stdio.h>
int main()
{
    int i,n,val[100],tem,j,tem1;
    scanf("%d",&n);
    tem=n%2+n/2;
     for(i=0;i<n;i++)
       scanf("%d ",val[i]);
    for(i=0,j=n-1;i<tem;i++,j--)
    {
        tem1=val[i];
        val[i]=val[j];
        val[j]=tem1;
    }
    for(i=0;i<n;i++)
        printf("%d ",val[i]);
    return 0;
}
