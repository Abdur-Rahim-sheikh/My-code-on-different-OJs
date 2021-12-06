#include<stdio.h>
#include<math.h>
int main()
{
    long long int j,k,a,b,n,i,count,boss,num;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&a,&b);




        for(j=a,boss=0;j<=b;j++)
        {

            if(j<=8)
            {
                for(k=1;k<=j;k++)
                {
                    // kp=&k;
                    if(j%k==0)
                    {

                        if((j/k)==k)
                            count++;
                        else
                        {
                            count=count+2;
                        }
                    }


                    if(boss<count){
                        boss=count;
                        num=j;
                    }

                }
            }
            else{
                count=0;
               // jp=&j;

                for(k=2;k<j/2-1;k++)
                {

                   // kp=&k;
                    if(j%k==0)
                    {
                         printf("%lld %lld\n",j,k);
                        if((j/k)==k)
                            count++;
                        else
                        {
                            count=count+2;
                        }
                    }

                }
                if(boss<count){
                    boss=count;
                    num=j;
                }

            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a,b,num,boss+2);

    }
    return 0;
}
