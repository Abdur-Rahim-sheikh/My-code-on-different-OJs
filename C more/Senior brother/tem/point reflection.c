#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int main()
{
    int i,j,k,m,n,test,x1,x2,y1,y2,p1,p2;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d %d",&x1,&x2,&y1,&y2);
        p1=x1>y1?(y1-(x1-y1)):(y1+(y1-x1));
        p2=x2>y2?(y2-(x2-y2)):(y2+(y2-x2));

        printf("%d %d\n",p1,p2);
    }
    return 0;
}
