#include<stdio.h>
#include<string.h>
int main()
{
    int i,a=0,n;
    char str[100],ch;
    scanf("%d ",&n);

    gets(str);
    ch=str[0];

    for(i=1;str[i]!='\0';i++)
    {
        if(ch==str[i])
            a++;
        else
        {
            ch=str[i];
        }
    }
    printf("%d\n",a);
    return 0;
}
