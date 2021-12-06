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
bool prime[1000000];
void prime_point(ll x){
    for(ll i=2;i*i<x;i++){
        if(prime[i])continue;
        for(ll j=i*i;j<x;j+=i)prime[j]=true;
    }
    return;
}
ll mod = 10000007;
int main(){
    ll i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);

    prime_point(1000000);
    vll primo;
    for(i=2;i<1000000;i++)if(!prime[i])primo.pb(i);
   //dbg(primo[78497]);
    while(true){
        cin>>n;
        if(n==0)break;
        ll sum=1;

        //4
        for(i=0;i<primo.size() and primo[i]<=n;i++){
            ll p = primo[i];
            ll power=1;
            while(n/p){
                power+=n/p;
                p*=primo[i];
            }
            //dbg(primo[i],power);
            ll now = ((power*(power+1))/2)%mod;
            sum = (sum*now+mod)%mod;
        }
        cout<<sum<<endl;
    }
    //free();   //if pointer array
    return 0;
}
