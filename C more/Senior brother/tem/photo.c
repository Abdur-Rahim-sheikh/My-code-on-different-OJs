#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    long long int i=0,j=0,k,n,l,c;

    scanf("%lld %lld",&k,&n);
    for(i=0;i<k;i++){
        for(l=0;l<n;l++){
        scanf("%lld",&c);
        if(c!='W' && c!='G' && c!='B')
            j=1;

    }
    }

    if(j==1)
        printf("#Color\n");
    else
        printf("#Black&White\n");
    return 0;
}
