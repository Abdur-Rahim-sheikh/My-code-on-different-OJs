#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int main()
{
    int i,j,k,m,n,test,sum;

    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        n--;
        if(n==0){printf("0\n");continue; }
        if(n%2==0)
        {
            sum=(n/2)*(n+1);
        }
        else{
            sum=(n-1)/2*(n)+n;
        }
        printf("%d\n",sum);
    }
    return 0;
}
