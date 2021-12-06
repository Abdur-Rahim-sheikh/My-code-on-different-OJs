#include<stdio.h>
int main()
{
    int i,n,k,f=0,rem[100];
    scanf("%d",&n);
    for(i=0;n>0;i++)
    {
        rem[i]=n%2;
        n=n/2;
    }
    i--;                     //if n=5 then i=3,but need i=2,actually i always need one less i,
    for(k=0; ;k++,i--)
    {
        if(rem[k]!=rem[i])
        {
            f++;
        }
        if(k==i || k==i-1 )
            break;
    }
    if(f==0)
      printf("Palindrome\n");

    else
        printf("NOT PALINDROME\n");
    return 0;

}
