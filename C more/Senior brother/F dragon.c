#include<stdio.h>
int main()
{
    int i,j,k,n,count,m=0,n=0;
    scanf("%d %d",&k,&n);
    struct dragon
    {
        int str;
        int bonus;
    }drg[n];
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&drg[i].str,&drg[i].bonus);
    }
    for(i=0;i<n;i++)
    {
        for(j=0,count=0;j<n;j++)
        {
            if(i==j)
                continue;

            if(drg[i].str>drg[j].str)
                m++;
            if(drg[i].str==drg[j].str && drg[i].bonus>drg[j].bonus)
                n++;
        }
    }
}
