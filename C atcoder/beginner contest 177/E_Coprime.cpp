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
        return os << '(' << p.first << gap << p.second << ')';
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
#define vll vector<ll>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n;
    vi prime(1e6,0),arr(n);
    for(auto &u : arr)cin>>u;
    int cnt=0,gcd=arr[n-1];
    for(i=n-1;i>=0;i--){
        bool coprime=true;
        gcd=__gcd(gcd,arr[i]);
        for(j=2;j*j<=arr[i];j++){
            if(arr[i]%j==0){
                if(prime[j])coprime=false;
                prime[j]=1;
            }
            while(arr[i]%j==0)arr[i]/=j;
        }
        if(arr[i]>1 and prime[arr[i]])coprime=false;
        prime[arr[i]]=1;
        if(coprime)cnt++;
    }
    if(cnt==n)printf("pairwise coprime\n");
    else if(gcd==1)printf("setwise coprime\n");
    else printf("not coprime\n");
    //free();   //if pointer array
    return 0;
}