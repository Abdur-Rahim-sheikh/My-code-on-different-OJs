#include<stdio.h>
#include<string.h>
int main()
{
    char string[50],l;

    int k,i,j,length;

    gets(string);

    length= strlen(string);
    printf("Given total character %d\n",length);
    for(i=0;i<length;i++)
    {
       l=string[i];
       if(string[i]==string[0] && i!=0)
            continue;

        for(j=0,k=0;j<length;j++)
        {
            if(l==string[j])
            {
                k++;
                string[j]=string[0];
            }
        }
        printf("%c is %d time in the string\n",l,k);

    }
    return 0;
}
