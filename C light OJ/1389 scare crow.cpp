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
    string field;
    cin>>test;
    while(test--){
        cin>>n>>field;
        for(i=0,cnt=0;i<n; ){
            while(field[i]!='.' && i<n)i++;
            if(i<n)cnt++;
            i+=3;
        }
        printf("Case %d: %d\n",++t,cnt);

    }

    //free();   //if pointer array
    return 0;
}
