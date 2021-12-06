#include<stdio.h>
#include<math.h>
int main()
{
    int rem,n,i;
    scanf("%d",&n);


    for(i=2;i<=sqrt(n)+1;i++)
        {


            if(n==0)
                return 0;
            rem=n%i;
            if(rem==0)
            {
                printf("NOT PRIME\n");
                return 0;
            }
        }
        printf("PRIME\n");
        return 0;
}
