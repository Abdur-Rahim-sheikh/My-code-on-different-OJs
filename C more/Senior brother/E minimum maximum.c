#include<stdio.h>
#include<math.h>
int main()
{
    long int big,small,value,sum=0;
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%ld",&value);
        sum=sum+value;
        if(i==0)
        {
            small=value;
            big=value;
        }
        if(value>=big)
            big=value;
        if(value<=small)
            small=value;

    }
    printf("%ld %ld\n",sum-big,sum-small);

    return 0;
}
