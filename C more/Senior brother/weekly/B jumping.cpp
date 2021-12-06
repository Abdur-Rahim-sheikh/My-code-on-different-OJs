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

    int i=0,j,k,m,n,val,t=0,cnt=0,test,prev;
    cin>>test;
    while(test--){
        scanf("%d %d",&n,&prev);
        while(--n){
            scanf("%d",&val);
            if(val>prev)t++;
            else if(val<prev)cnt++;
            prev=val;
        }
        printf("Case %d: %d %d\n",++i,t,cnt);
        t=cnt=0;
    }

    //free();   //if pointer array
    return 0;
}
