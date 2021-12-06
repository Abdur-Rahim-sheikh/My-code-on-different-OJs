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
    double a,b,dis,x,y,v,highest=INF;

    scanf("%lf %lf",&a,&b);
    cin>>n;
    while(n--){
        scanf("%lf %lf %lf",&x,&y,&v);

        dis=sqrt(((a-x)*(a-x))+((b-y)*(b-y)));
        //cout<<dis<<endl;
        if((dis/v)<highest)highest=(dis/v);
    }
   printf("%0.8lf\n",highest);
   //cout<<highest;
    //free();   //if pointer array
    return 0;
}
