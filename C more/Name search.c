#include<stdio.h>
#include<string.h>

int main()
{
	int i,j=0,n,size,value;
	char name[50],key[20],string[1000];
	gets(string);
	scanf("%s",key);
	for(i=0;string[i]!='\0';i++,j++)
    {
        name[j]=string[i];
        if(string[i+1]==' ' || string[i+1]=='\0')
        {
            name[j+1]='\0';
            j=-1;
            i++;

            if(strcmpi(name,key)==0)
            {
                printf("YES%\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
