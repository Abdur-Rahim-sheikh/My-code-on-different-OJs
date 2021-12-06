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
    double x1,x2,y1,y2,a,b,c,d,result,dx,dy,cx,cy;
    cin>>test;
    while(test--){
        scanf("%lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&b,&c,&d);

        double mini=x1-d,maxi=x1+d,dx,assumed_b;
        int iterate=230;
        while(iterate--){
            dx=(mini+maxi)/2;

            dy=y1+sqrt(d*d-(dx-x1)*(dx-x1));
            cx=dx+c;
            cy=dy;

            assumed_b=sqrt((x2-cx)*(x2-cx)+(y2-cy)*(y2-cy));
            if(assumed_b<b)maxi=dx;
            else mini=dx;
        }

        ///cout<<cx<<' '<<cy<<' '<<dx<<' '<<dy<<endl;
        printf("Case %d:\n%0.7lf %0.7lf %0.7lf %0.7lf\n",++t,cx,cy,dx,dy);
    }

    //free();   //if pointer array
    return 0;
}
