#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int main()
{
    int i=0,j,k,m,n,test,sum,temt,t,l;
    char sen[25][10000],tem,ch;
    scanf("%d%*c",&test);

    for(i=0;i<test;i++)
    {

            for(j=0;  ;j++){

                scanf("%c",&sen[i][j]);


                if(sen[i][j]=='\n')
                {
                    sen[i][j]='\0';
                    break;
                }
            }
    }
    for(i=0;i<test;i++)
    {

        if(sen[i][1]!=' ' && sen[i][1]!='\0')
        {
            ch=sen[i][0]|32;
            sen[i][1]=sen[i][1]&95;
        }

        else ch=sen[i][0]&95;

        for(j=1;sen[i][j]!='\0';j++)
        {
            if(sen[i][j]==' ')
            {
                printf("%cay",ch);
                ch=sen[i][j+1];
            }


            printf("%c",sen[i][j]);

            if(sen[i][j]==' ')
                j++;
        }
        printf("%cay\n",ch);
    }
    return 0;
}

