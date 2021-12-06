#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int main()
{
    int i,j,k,l,m,n,test,ara1[100],ara2[100],pow,num1,num2,sum,rem;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&m,&n);
        for(i=0;m>0;i++)
        {
            ara1[i]=m%10;
            m=m/10;
        }
        for(j=0;n>0;j++)
        {
            ara2[j]=n%10;
            n=n/10;
        }
        for(l=i-1,num1=0,pow=1;l>=0;l--) {
            num1=num1+ara1[l]*pow;
            pow=pow*10;
        }
        for(k=j-1,num2=0,pow=1;k>=0;k--) {
            num2=num2+ara2[k]*pow;
            pow=pow*10;
        }
        sum=num1+num2;
        while(1)
        {
            rem=sum%10;
            if(rem!=0)
                break;
            sum=sum/10;
        }
        while(sum>0)
        {
            printf("%d",sum%10);
            sum=sum/10;
        }
        printf("\n");
    }
    return 0;
}
