#include<stdio.h>
int main()
{
    int arry[7],shorten[7];
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arry[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0,k=0;j<n;j++)
        {
            if(arry[i]>=arry[j])    ///logic is the problem.
            {
                shorten[k++]=arry[i];
            }
        }

    }
    for(i=0;i<n;i++)
    {
        printf("%d ",shorten[i]);
    }
    printf("\n");
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",shorten[i]);
    }
    printf("\n");
    return 0;

}


