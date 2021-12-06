#include<stdio.h>
int main()
{
    int a,b,c;
    for( ; ; )
    {
        scanf("%d",&a);
        if(a==42)
            return 0;
        printf("%d\n",a);
    }
    return 0;
}
