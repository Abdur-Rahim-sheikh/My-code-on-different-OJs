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
#define INF 1073741824
using namespace std;
bool grid[2000][2000],checked[row];
int main()
{

    int i,j,k,m,n,val,t=0,test,highery=0,lowery=INF,higherx=0,lowerx=INF;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&k,&m);
        grid[k][m]=true;
        if(k>highery)highery=k;
        if(k<lowery)lowery=k;

        if(m>higher)higherx=k;
        if(m<lower)lowery=k;
    }

    for(i=lowery;i<=highery;i++){

        while(1){
                int start=i;
            for(j=lowerx;j<=higherx;j++){
                if()
            }
        }

    }
    //free();   //if pointer array
    return 0;
}
