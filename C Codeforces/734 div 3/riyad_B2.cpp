#include <bits/stdc++.h>
#define ll long long
#define rep(I,N) for(I=0;I<N;I++)
#define repp(I,A,B) for(I=A;I<=B;I++)
#define rrep(N,I) for(I=N;I>=0;I--)
#define rrepp(A,B,I) for(I=A;I>=B;I--)
#define MS0(X) memset(X,0,sizeof(X))
#define MS1(X) memset(X,-1,sizeof(X))
#define F first
#define S second
#define mp make_pair
#define Mod 1000000007
#define pb push_back
#define RF freopen("riyad.txt","r",stdin)
#define WF freopen("out.txt","w",stdout)
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define all(n) (n).begin(),(n).end()
#define vi vector < int >
#define vll vector < long long int > 

using namespace std;

typedef unsigned long long ull;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""),__print(i); cerr << "}";}
void _print() {cerr << endl;}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void run_case(){
    ll n , i , j , k , cnt = 0 , x;
    map < int , int > occ;
    map < int , int > res;
    vi val;
    cin>>n>>k;
    vector < int > a[n+2];
    rep(i,n){
        cin>>x , occ[x]++;
        a[x].pb(i+1);
    }
    for(i=1;i<=n;i++){
        if(occ[i] >= k){
            for(j = 1 ; j <= k ; j++)
                res[a[i][j-1]] = j;
        }
        else if(occ[i] >= 1){
            for(j = 0 ; j < a[i].size() ; j++)
                val.pb(a[i][j]);
        }  
    }
    x = val.size();
    x = x / k;
    j = 1;
    rep(i,val.size()){
        if(!x)break;
        res[val[i]] = j++;
        if(j > k)
            x--,j = 1;
    }
    for(i=1;i<=n;i++)
        cout<<res[i]<<' ';
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //RF;
    //WF;
    int tc;
    cin>>tc;
    while(tc--){
        run_case();
    }
    return 0;
}