#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    ll i,j,k,m,n,val,t=0,test;

    vector<int>arr[10];
    bool checked[10]={false};
    for(i=0;i<8;i++){
        scanf("%d",&arr[i]);
    }
    cin>>m;
    for(i=0;i<m;i++){
        scanf("%d %d",&j,&k);
        arr[i].push_back(j);
        arr[j].push_back(i);
    }
    for(i=1;i<=8;i++){
        BFS(i);
    }
    //free();   //if pointer array
    return 0;
}
