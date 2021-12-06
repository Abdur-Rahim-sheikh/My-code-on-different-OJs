#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int a,b,c,ab,abc,n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        ab=(a+b+abs(a-b))/2;
        abc=(ab+c+abs(ab-c))/2;


        /**if(a>b && a>c)
        {
            abc=a;
        }
        else if(b>a && b>c)
        {
            abc=b;
        }
        else
        {
            abc=c;
        }
*/

        if(a+b<abc || b+c<abc || c+a<abc)
            printf("Case %d: Invalid\n",i+1);
        else if(a==b && b==c && a==c)
            printf("Case %d: Equilateral\n",i+1);
        else if(a==b || b==c || a==c )
            printf("Case %d: Isosceles\n",i+1);
        else
            printf("Case %d: Scalene\n",i+1);
    }
    return 0;
}
