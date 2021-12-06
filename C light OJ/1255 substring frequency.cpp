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
#define mp make_pair
#define pb push_back
using namespace std;

int main()
{
    int i,j,k,m,n,t=0,cnt=0,test;
    int val;
    string s,subs;
    cin>>test;
    while(test--){
        cin>>s>>subs;
        int val = -1;
        cnt=0;
        while(1){
           val = s.find(subs,val+1);
           if(val!=string:: npos)cnt++;
           else break;
        }

        printf("Case %d: %d\n",++t,cnt);
    }
    //free();   //if pointer array
    return 0;
}
