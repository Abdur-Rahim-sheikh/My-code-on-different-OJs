#include<stdio.h>
#include<string.h>
int main()
{
    char name[100],name2[100];
    int i,j,k,size,size2;
    gets(name);
    size=strlen(name);
    gets(name2);
    size2=strlen(name2);
    ///printf("%s%s",name,name2);
    for(i=size,j=0;i<size+size2;i++,j++)
    {
        name[i]=name2[j];
    }
    name[i]='\0';
    printf("%s\n",name);
    return 0;
}
