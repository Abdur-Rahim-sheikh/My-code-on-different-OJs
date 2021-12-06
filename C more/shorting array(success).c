#include<stdio.h>
int main()
{
    int arry[50],shorten[50];
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
            if(i==j)
                continue;
            if(arry[i]>=arry[j])
            {
                k++;
            }
        }
        shorten[k]=arry[i];
    }
    printf("Ascending\t:");
    for(i=0;i<n;i++)
    {
        printf("%d ",shorten[i]);
    }
    printf("\nDescanding\t:");
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",shorten[i]);
    }
    printf("\n");
    return 0;

}


