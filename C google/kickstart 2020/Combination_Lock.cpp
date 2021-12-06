#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 1073741824
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
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define x first
#define y second
#define vi vector<ll>
#define vvi vector<vi>
#define vll vector<ll>
#define on(val,pos) (val|(1<<pos))
#define off(val,pos) (val&(~(1<<pos)))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//ll row[8]={0,-1,0,1,1,-1,-1,1};
//ll col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
vi wheel;
ll query(ll x,ll n){

    ll sum=0;
    for(ll i=0;i<wheel.size();i++){
        sum+=min(abs(wheel[i]-x),wheel[i]+n-x);
    }
    return sum;
}
int main(){
    ll i,j,k,n,m,val,t=0,test,w;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>w>>n;
        wheel.clear();
        wheel.resize(w);
        for(auto &u: wheel)cin>>u;
        ll sum=accumulate(all(wheel),0);
        for(i=1;i<=n;i++){
            sum=min(sum,query(i,n));
        }

        
        printf("Case #%lld: %lld\n",++t,sum);
    }
    //free();   //if poller array
    return 0;
}
