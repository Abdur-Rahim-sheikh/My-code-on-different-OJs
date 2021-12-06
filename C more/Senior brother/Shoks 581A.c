#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c,sum,left;
    scanf("%d %d",&a,&b);
    sum=a+b;
    a=(sum+abs(a-b))/2;             ///now a always greater
    b=sum-a;                        ///b always shorter
    left=(a-b)/2;
    printf("%d %d\n",b,left);
    return 0;
}
