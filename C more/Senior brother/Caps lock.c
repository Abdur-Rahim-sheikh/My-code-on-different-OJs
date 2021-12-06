#include<stdio.h>
#include<string.h>
int main()
{
    int i,size,k,l=0;
    char word[120];
    size=strlen(gets(word));
    if(word[0]>='a'  && word[0]<='z')
        l=1;
    for(i=0,k=0;word[i]!='\0';i++)
    {
        if(word[i]>='A' && word[i]<='Z')
            k++;
    }
    if(size==k+l)
    {
        if(word[0]>='a' && word[0]<='z')
             word[0]=word[0]-'a'+'A';
        else
            word[0]=word[0]-'A'+'a';
        for(i=1;word[i]!='\0';i++)
        {
            word[i]=word[i]-'A'+'a';
        }
    }
    printf("%s\n",word);
    return 0;
}
