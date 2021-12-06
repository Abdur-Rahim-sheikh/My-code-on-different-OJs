#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483648
#define ll long long
#define endl '\n'
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
//replace less<int> to less_equal<int> to take duplicate values


bool solve(ll n, vll &ans){
    ll i,j,k;
    for(i=-500;i<=500;i++){
            ll a = i*i*i;
            for(j=max(0ll,i);j<=500;j++){
                ll c = n-j*j*j-a;
                
                k = cbrt(abs(c)+0.000000001)* (c<0?-1:1);
                if(k*k*k==c){
                    ans={i,j,k};
                    return true;
                }
            }
    }
    return false;
}
int main(){
    ll i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    
    scanf("%lld",&test);
    vi arr(200);
    iota(all(arr),1);
    while(test--){
        scanf("%lld",&n);
        //n = arr[t++];
        vll ans;
        bool flag = solve(n,ans);
        if(n==51 or n==87 or n==108 or n==111){
            flag = true;
            if(n==51)ans = {-796,602,659};
            else if(n==87)ans = {-4126,-1972,4271};
            else if(n==108)ans = {-1165,-948,1345};
            else ans = {-881,-296,892};
        }
        if(flag)printf("%lld %lld %lld\n",ans[0],ans[1],ans[2]);
        else printf("impossible\n");
    }
    //free();   //if pointer array
    return 0;
}
