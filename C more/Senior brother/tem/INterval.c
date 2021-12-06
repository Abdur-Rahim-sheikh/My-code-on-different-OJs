#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    char a;
    int i=0,j=0,k,n;
    scanf("%d %d",&k,&n);

    if(k==0 && n==0)
        printf("NO\n");
    else if(k==n || k+1==n ||k==n+1)
        printf("YES\n");
    else printf("NO\n");

    return 0;
}
