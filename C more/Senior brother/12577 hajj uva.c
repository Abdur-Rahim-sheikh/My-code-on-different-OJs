#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    long long int i=1,j,k,m,n,rem,div,val,previous;
    char name[50],umrah[50]="Umrah";
    while(scanf("%s",name))
    {
        if(strcmp(name,"*\0")==0)
            break;
        if(strcmp(name,umrah)==0)printf("Case %lld: Hajj-e-Asghar\n",i);
        else printf("Case %lld: Hajj-e-Akbar\n",i);

        i++;
    }
    return 0;
}
