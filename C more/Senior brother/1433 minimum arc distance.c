#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int main()
{
     int i,j,k,m,n,rx,ry,x1,x2,y1,y2,tem,test,dif;
     double radious,length,acb;
     scanf("%d",&test);
     for(i=0;i<test;i++)
     {
         scanf("%d %d %d %d %d %d",&rx,&ry,&x1,&y1,&x2,&y2);

         if(y1>y2){
            tem=y1;
            y1=y2;
            y2=tem;
            tem=x1;
            x1=x2;
            x2=tem;

         }
         printf("%d %d %d %d\n",x1,y1,x2,y2);
         dif=abs(x1-x2);
         y2=y2+dif;

        length=(double)(y2-y1);       //x1-x2==0
        radious=sqrt((rx-x1)*(rx-x1)+(ry-y1)*(ry-y1));
        acb=radious*atan(length/radious);
        printf("%0.8lf %d %lf %d\n",acb,y2,radious,dif);
     }


    return 0;
}
