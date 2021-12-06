//the magic method how to change latter form small to big or vice versa.

#include<stdio.h>
int main()
{
    int n,i;
    char ch,nch;

    printf("Press how many u want to check:");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        scanf("%c",&ch);

        if(ch>='a' && ch<='z')
        {
            nch=ch-'a'+'A';
            printf("Capital latter of %c is %c\n",ch,nch);
        }
        else if(ch>='A' && ch<='Z')
        {
            nch=ch-'A'+'a';
            printf("small latter of %c is %c\n",ch,nch);
        }
        else
        {
            printf("NOT %c alphabet\n",ch);
        }
    }
    return 0;
}
