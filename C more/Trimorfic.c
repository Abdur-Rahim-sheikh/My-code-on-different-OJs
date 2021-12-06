#include<stdio.h>
#include<math.h>
int main()
{
    int n,cn,a,rem,i,s;
    printf("Give a integer number:");
    scanf("%d",&n);
    s=n;
    cn=n*n*n;
    for(i=0;n>0;i++)
    {
        n=n/10;
    }
    a=pow(10,i);
    rem=cn%a;
    if(rem==s)
        printf("%d is a trimorfic cause it's cubic number is %d\n",s,cn);
    else
        printf("%d is not a trimorfic cause it's cubic number is %d\n",s,cn);
    return 0;

}
