#include<stdio.h>
int primef(int n);
int main()
{
    int i,n,array[10];
    printf("How much number do you want to cheak:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Give number %d:",i+1);
        scanf("%d",&array[i]);
    }
    for(i=0;i<n;i++)
    {
         if(1==primef(array[i]))
            printf("%d is A PRIME number\n",array[i]);
        else
            printf("%d is NOT a PRIME number\n",array[i]);
    }
    return 0;
}
int primef(int n)
{
    int i,j;
    if(n<2)
        return 0;
    if(n=2)
        return 1;
    if(n%2==0)
        return 0;
    for(i=3;i<=n/2;i=i+2)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}


