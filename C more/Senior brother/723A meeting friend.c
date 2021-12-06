#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c,ab,abc,ab1,abc1;
    scanf("%d %d %d",&a,&b,&c);

        ab=(a+b+abs(a-b))/2;
        abc=(ab+c+abs(ab-c))/2;
        ab1=(a+b-abs(a-b))/2;
        abc1=(ab1+c-abs(ab1-c))/2;
        printf("%d\n",abc-abc1);
    return 0;
}
