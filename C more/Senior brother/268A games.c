#include<stdio.h>
int main()
{
    int i,n,j,k,change1=0,change2=0;
    int home[100],guest[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&home[i],&guest[i]);
    }
    for(j=0;j<n;j++)           //i use the nested for loop to cheek condition for each team with everyone as the story wanted.
    {
        for(k=0;k<n;k++)
        {
            if(j==k)
                k++;


                if(home[j]==guest[k])
                {
                    change1++;
                }


        }

    }


    printf("%d\n",change1);
    return 0;
}
