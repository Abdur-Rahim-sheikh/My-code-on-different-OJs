#include<stdio.h>

int main()
{
    int value[50],sign=0,count;

    int k,i,j,n,l;

    scanf("%d",&n);




    for(i=0;i<n;i++)

    {
        scanf("%d",&value[i]);
    }
    for(i=0;i<n;i++)
    {
        l=value[i];
        for(j=i+1,count=0;j<n;j++)
        {
            if(value[i]==value[j])
            {
                sign=1;
                count++;
                j--;                   ///ha ha ha only the condition has made a great mistake,if any first digit also given in last it will make all the last number that.
                n--;
                for(k=j;k<n;k++)
                    value[j]=value[j+1];

            }
        }
        if(count>0)
        printf("%d is duplicated %d time\n",l,count);
    }
    if(sign==0)
        printf("No duplicate has been given.");
    return 0;
}
