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
                k++;                //if you input 5 7 2 3,output will be
                                    //3 3 3 7 the third 3 has come for the equal inthe condition
            }
            shorten[k]=arry[i];
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


