#include<stdio.h>
int main()
{
    int n,p,h,ph,i,j=0,width;
    scanf("%d %d",&n,&h);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ph);
        if(ph>h)
            j++;
    }
    p=n-j;
    width=p+2*j;
    printf("%d\n",width);
    return 0;
}
