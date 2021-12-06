#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    long long int i,dollar=0,n,val,rem=0,point=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&val);
        rem=rem-val;

        if(rem<0)
        {

            dollar=dollar+abs(rem);
            point=0;
        }
        else
        {
            point=rem;
        }

        rem=val+point;
    }
    printf("%lld\n",dollar);
    return 0;
}
