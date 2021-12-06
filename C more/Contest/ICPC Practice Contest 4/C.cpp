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
//replace less<int> to less_equal<int> to take duplicate values
const int sz = 2000006;
bool nonprime[sz];

void prime_factorize(){
    for(int i=2;i*i<=sz;i++){
        if(nonprime[i])continue;
        for(int j=i*i;j<sz;j+=i) nonprime[j]=true;
    }
}
int possible(ll n){
    ll a = sqrt(n);
    while((a+1)*(a+1)<=n)a++;
    if(a*a==n){
        if(!nonprime[a])return 1;
        else return 2;
    }
    else return 0;
}
int main(){
    ll i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    prime_factorize();
    vll primo;
    for(i=2;i<sz;i++)if(!nonprime[i])primo.pb(i);

    scanf("%lld",&test);
    while(test--){
        scanf("%lld",&n);
        ll arr[n];
        ll ans[n];
        ll t;
        
        for(i=0;i<n;i++)   scanf("%lld",&arr[i]);
        sort(arr,arr+n,greater<ll>());
        for(i=0,t=0;i<n;i++){
            val = arr[i];
            
            ll cnt=0;
            int checker = possible(val);
            if(checker==0 or val<4)    continue;
            else if(checker==1){
                ans[t++]=i+1;
                continue;
            }
            for(j=0;j<primo.size() and primo[j]*primo[j]*primo[j]<=val;j++){
                cnt=1;
                while(val%primo[j]==0){
                    val/=primo[j];
                    cnt++;
                }
                if(cnt>1)break;
            }

            if(val == 1 and cnt>2 and !nonprime[cnt])ans[t++]=i+1;
        }
        
        if(t==0){
            printf("No supporter found.\n");
        }
        else{
            for(i=0;i<t;i++){
                printf("%lld ",ans[i]);
            }
            printf("\n");
        }
    }
    //free();   //if pointer array
    return 0;
}
