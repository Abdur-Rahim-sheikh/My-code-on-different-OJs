#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int storage[105];
int checker(int n,int std);
int main()
{
    int i,j=5,l,n;
    storage[0]=1;
    while(1)
    {
        scanf("%lld",&n);
        if(n==0)
            return 0;

        for(i=1;i<=n;i++)
        {
            l=storage[i-1]+j;



            if(l>n)
            {
                 l=l-n;
            }
            printf("%d\n",l);

            storage[i]=150;

           /** for(l=storage[i];checker(l,n)!=0;l++)
            {
                if(l>n)
                    l=l-n;
            }
            */
            checker(l,n);

           // storage[i]=l;

            //storage[i]=storage[i]+j;

            if(storage[i]==13)
            {
                if(i==n-1)
                {
                    printf("%  lld",j-1);
                    return 0;
                }
                else
                {
                    i=0;
                    j++;
                }
            }
        }
    }



    return 0;
}
int checker(int n,int std)
{
    int i;
    if(n>std)
        n=n-std;
     printf("*******%d\n",n);
    for(i=0;storage[i]<101;i++)
    {
        if(n==storage[i])
            return checker(n+1,std);
       /// printf("%d\n",n);
    }
    storage[i]=n;
    return 0;
}

