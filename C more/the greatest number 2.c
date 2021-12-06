#include<stdio.h>
#include<math.h>
int main()
{
    int i=0,n,a,MaiorAB=0;
    printf("How digit do you want to give??\nENTER=");
    scanf("%d",&n);
    for(  ;i<n;i++)
    {
        printf("ENTER number:");
        scanf("%d",&a);
        MaiorAB=(MaiorAB+a+abs(MaiorAB-a))/2;    //interesting law to findout the greatest number in two number as maiorAB=greatestAB
    }

    printf("%d eh o maior i.e Thats the greatest number\n",MaiorAB);
    return 0;
}
