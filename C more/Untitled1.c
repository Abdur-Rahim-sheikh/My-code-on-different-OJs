#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    long long int i=0,j,k,n,sum=0,avg;
    char ifname[100];

    FILE *fp;
    gets(ifname);
    fp=fopen(ifname,"r");
    while(!feof(fp))
    {
        fscanf(fp,"%lld",&n);
        sum=sum+n;
        i++;
        printf("%lld\n",n);
    }
    avg=sum/i;
    printf("%lld",avg);
    return 0;
}
