#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int GCD(int m,int n);
int main()
{
    int i,j,k,m,n,test,sum,ara[1000],previous,val;

    scanf("%d",&test);
    while(test--){
        //for(n=0;scanf("%d",&ara[i])!=EOF;n++);
        n=0;
        while(scanf("%d",&ara[n])!=EOF){n++;}
        for(i=0,previous=0;i<n;i++){
            for(j=i+1;j<n;j++){
                val=GCD(ara[i],ara[j]);
                if(val>previous)
                    previous=val;
            }

        }
        printf("%d\n",previous);
    }
    return 0;
}
int GCD(int m,int n)
{
	int divisor,divident,rem=1;
	divident=(m>n?m:n);
	divisor=(m>n?n:m);

	while(rem!=0)
	{
		rem=divident%divisor;
		divident=divisor;
		divisor=rem;
	}

	return divident;      //which  actually carrying divisor value

}
