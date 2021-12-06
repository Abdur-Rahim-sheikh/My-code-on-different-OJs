#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483648
#define mod 998244353
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
ll power(ll base, ll n){
  base %= mod;
  ll result = 1;
  while(n > 0){
    if(n & 1) result = (result * base) % mod;
    base = (base * base) % mod;
    n >>= 1;
  }
  return result;
}
ll modInverse(ll n,ll MOD){
  return power((ll)n,(ll)MOD-2);
}
int main(){
    ll i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    vll fact(200005);
    fact[0]=fact[1]=1;
    for(i=2;i<200005;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    cin>>test;
    while(test--){
        cin>>n;
        vll arr(n);
        for(auto &u: arr)cin>>u;
        sort(all(arr),greater<ll>());
        dbg(arr);
        if(arr[0]>arr[1]+1)printf("0\n");
        else if(arr[0]==arr[1])printf("%lld\n",fact[n]);
        else{
            ll cnt=1;
            for(i=2;i<n;i++){
                if(arr[i]==arr[i-1])cnt++;
                else break;
            }
            ll left,right,nn,ans=0,r=0,tem;
            left = cnt;right=nn=n-cnt-1;
            dbg(right);
            while(right>=0){
                // cnt = abc
                // n-cnt-1 = 132

                // kawser code here.. 
                // your left is my cnt, and your right is my n-cnt-1
                ll lower = (fact[nn-r]*fact[r])%mod;
                ll nncr = (fact[nn]*modInverse(lower,mod)+mod)%mod;
                
                tem = (fact[left]*(fact[right]*nncr)%mod+mod)%mod;
                dbg(tem);
                ans = (ans+tem)%mod;
                left++;
                right--;
                r++;

            }

            ans = (fact[n]-ans+mod)%mod;
            printf("%lld\n",ans);

        }
    }
    //free();   //if pointer array
    return 0;
}
