#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define p1(n) printf("showing %d\n",n)
#define p2(m,n) printf("showing %d %d\n",m,n)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define x first
#define y second
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int arr[202],brr[202],n,m;

int solve(int num){
    for(int i=1;i<n;i++){
        int x=num|(arr[i]&brr[0]);
        for(int j=1;j<m;j++){
            num|=(arr[i]&brr[j]);
            if(num<x)x=num;
        }
    }
}
int main(){
    int i,j,k,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    int ans=INF;
    cin>>n>>m;
    for(i=0;i<n;i++)scanf("%d",&arr[i]);
    for(i=0;i<m;i++)scanf("%d",&brr[i]);
    for(i=0;i<m;i++){
        ans=min(ans,solve(arr[0]&brr[i]));
    }
    //free();   //if pointer array
    return 0;
}
