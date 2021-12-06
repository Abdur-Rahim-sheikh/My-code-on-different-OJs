#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;

    scanf("%d",&n);

    for(;n>0;)
    {
        if(n>0)
        {
            printf("I hate ");
            n--;
        }
        if(n>0)
            printf("that ");
        if(n>0)
        {
            printf("I love ");
            n--;
        }
        if(n>0)
            printf("that ");
        if(n==0)
            printf("it\n");
    }
    return 0;
}
