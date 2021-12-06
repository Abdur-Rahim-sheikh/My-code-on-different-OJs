#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<set>
#include<queue>
#include<stack>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
string a="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector<char> permute;
map<char,bool> checked;
int printed;
void next(int n,int k){
    if(printed == k)return;
    if(permute.size() == n){
        for(auto u: permute)printf("%c",u);
        printf("\n");
        printed++;
    }
    for(int j = 0;j<n;j++){
        if(checked[a[j]]==true)continue;

        checked[a[j]] = true;
        permute.pb(a[j]);
        next(n,k);
        checked[a[j]]=false;
        permute.pop_back();
    }
}
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;

    cin>>test;
    while(test--){
        scanf("%d %d",&n,&k);
        printed =0;
        printf("Case %d:\n",++t);
        next(n,k);
    }



    //free();   //if pointer array
    return 0;
}
