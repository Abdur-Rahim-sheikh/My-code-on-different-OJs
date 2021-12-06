#include<stdio.h>
int main()
{
    int i,j,count=0;
    long long int n,a[5];
    for(i=0;i<4;i++)
    {
        scanf("lld",&a[i]);
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i]==a[j])
            {
                count++;
            }

        }
    }
    printf("%d\n",count);
    return 0;
}
