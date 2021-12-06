#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483648
#define ll long long
#define PI (2*acos(0.0))
using namespace std;
char gap = 32;
template<typename T> 
ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << '{'; 
    for (const auto &x : v) os << gap << x;
        return os << '}'; 
}
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) {
        return os << '(' << p.first <<gap<<','<< gap << p.second << ')';
}
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { 
    cerr << ' ' << H;
     dbg_out(T...); 
}
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')'<<':', dbg_out(__VA_ARGS__)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define on(val,pos) (val|(1<<pos))
#define off(val,pos) (val&(~(1<<pos)))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
    ll i,j,k,n,m,val,t=0,test,a,b,c;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n>>a>>b>>c>>m;
        vll arr(n);
        ll x=0;
        ll mx=0;
        for(ll i=0;i<n;i++){
            arr[i]=x+c;
            x=(x*a+b)%m;
            mx= max(arr[i],mx);
        }
        
        sort(all(arr),greater<ll>());
        vll sum(2*n,0);
        ll prog=0;

        for(i=0;i<n;i++){
            //dbg(arr[i],sum[i]);
            arr[i]-=sum[i];
            if(arr[i]<0){
                ll j=i+1;
                ll val = -arr[i],left=sum[j];
                while(j<n and val>0){
                    ll mini = min(max(arr[j]-left,0ll),k);
                    arr[j]-=mini;
                    k-=mini;
                    left+=arr[j+1];
                    j++;
                }
                if(j==n){
                    break;
                }
                arr[i]=0;
            }
            
            sum[i+1]+=1;
            sum[i+1+arr[i]]-=1;
            sum[i+1]+=sum[i];
            
        }
        
        if(i<n or sum[n]!=0)cout<<"SAD"<<endl;
        else cout<<"HAPPY"<<endl;
    }
    //free();   //if pointer array
    return 0;
}
