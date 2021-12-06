#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#include<iomanip>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test;
    double arr[200000]={0},sum=0;
    for(i=1;i<100001;i++){
        sum+=1/(1.00*i);
        arr[i]=sum;
    }
    cin>>test;
    while(test--){
        scanf("%d",&val);

       // cout<<setprecision(7)<<val*arr[val]<<endl;
        printf("Case %d: %0.7lf\n",++t,val*arr[val]);
    }

    //free();   //if pointer array
    return 0;
}
