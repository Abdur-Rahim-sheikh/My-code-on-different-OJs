#include<stdio.h>

int main()
{
    int value[50],sign=0,count;

    int k,i,j,n,l;

    scanf("%d",&n);




    for(i=0;i<n;i++)                  ///to scan value

    {
        scanf("%d",&value[i]);
    }
    for(i=0;i<n;i++)          ///to call a value
    {
        l=value[i];           //to save the value
        for(j=i+1,count=0;j<n;j++)    ///to compare all value
        {
            if(value[i]==value[j])    ///condition if match
            {
                sign=1;                /// it the loop enter a single time the value will be activated
                count++;

                n--;                   ///decresing one length  so that below for loop relay decress one.
                for(k=j;k<n;k++)
                    value[k]=value[k+1];
                    j--;

            }
        }
        if(count>0)
        printf("%d is duplicated %d time\n",l,count);
    }
    if(sign==0)
        printf("No duplicate has been given.");
    return 0;
}
