#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test;

    double x1,x2,y1,y2,r1,r2,d,A,B;
    cin>>test;
    while(test--){
        scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);
         d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
         if(r1+r2<=d)printf("Case %d: 0\n",++t);
         else if(d+r1<=r2)printf("Case %d: %0.8lf\n",++t,PI*r1*r1); ///r1 is inner r2 circle
         else if(d+r2<=r1)printf("Case %d: %0.8lf\n",++t,PI*r2*r2);
         else {

            A=acos((r1*r1+d*d-r2*r2)/(2*r1*d));
            B=acos((r2*r2+d*d-r1*r1)/(2*d*r2));

            double area1 = 0.5*r1*r1*A;
            double area2 = 0.5*r2*r2*B;

            double s=(r1+r2+d)/2;
            double area=sqrt(s*(s-r1)*(s-r2)*(s-d));

            printf("Case %d: %0.8lf\n",++t,2*(area1+area2-area));
        }

    }


    //free();   //if pointer array
    return 0;
}
