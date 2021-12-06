#include<stdio.h>
int main()
{
    int wm,i,n,sign=0;
    scanf("%d",&n);
    if(n%2==1 || n==2){
        printf("NO\n");
        return 0;
    }
   /** for(i=2;i<n/2+1;i=i+2)
    {
        if((n-i)%2==0)
        {
            printf("YES\n");
            return 0;
        }
    }*/
   else
    printf("YES\n");
    return 0;

}
