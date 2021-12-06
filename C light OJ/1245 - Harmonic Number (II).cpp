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

int main(){
    ll i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        ll last=n,k;
        ll sum=0;
        for(i=1;i*i<=n;i++){
            k=n/i;
            sum+=k;
            sum+=(last-k)*(i-1);
            last=k;
        }
        sum+=(last-(i-1))*(i-1);
        printf("Case %lld: %lld\n",++t,sum);
    }
    //free();   //if pointer array
    return 0;
}
/*
How about the following idea. Say n = 36. So, the result is.
36/1 + 36/2 + 36/3 + ... + 36/36
Now,
36/1 = 36
36/2 = 18
from these two parts we are sure that
36/36 = 1
36/18 = 2
So, 36/19 = 36/20 = 36/21 = ... = 36/36 = 1
So, 36/19 + 36/20 + ... + 36/36 = 36 - 18 = 18.
Again,
36/2 = 18
36/3 = 12
from these two parts we are sure that
36/18 = 2
36/12 = 3
So, 36/13 = 36/14 = ... = 36/18 = 2
So, 36/13 + 36/14 + ... + 36/18 = (18 - 12)*2
*/
