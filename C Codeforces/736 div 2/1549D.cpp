#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483648
#define mod 1000000007
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
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vi>
#define vvll vector<vector<ll>>
#define on(val,pos) (val|(1<<pos))
#define off(val,pos) (val&(~(1<<pos)))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//ll row[8]={0,-1,0,1,1,-1,-1,1};
//ll col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//replace less<ll> to less_equal<ll> to take duplicate values
vvll sparse;

ll range_gcd(ll a,ll b){
    ll k = log2(b-a+1);
    return __gcd(sparse[a][k],sparse[b-(1<<k)+1][k]);
}
int main(){
    ll i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        vector<ll> arr(n);
        for(ll &u: arr)scanf("%lld",&u);
        if(n==1){
            printf("1\n");
            continue;
        }

        vector<ll> brr(n-1);
        m = n-1;
        k = log2(m)+1;
        sparse.clear();
        sparse.resize(m,vector<ll>(k));
        for(i=1;i<n;i++){
              sparse[i-1][0] = brr[i-1] = abs(arr[i]-arr[i-1]);
        }
        for(j=1;j<k;j++){
            for(i=0;i+(1<<j)<=m;i++){
                sparse[i][j]=__gcd(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
            }
        }

        // dbg(sparse);
        ll bestSubarray = 1;
        for(i=0;i<m;i++){
            ll middle = i;
            if(brr[i]==1)continue;  ///Why if ommit the line decrease the value??
            for(ll x=m/2;x>=1;x/=2){
                while(x+middle<m and range_gcd(i,x+middle)>=2) middle+=x;
            }
            bestSubarray = max(bestSubarray,middle-i+2);
        }
        printf("%lld\n",bestSubarray);
    }
    //free();   //if poller array
    return 0;
}
