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
#define vvi vector<vi>
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
    string s;
    cin>>s;
    s+='$';
    n=s.size();
    k=log2(n-1)+1;
    vi p(n),c(n);
    vector<pair<char,int>> a(n);
    for(i=0;i<n;i++)a[i]={s[i],i};

    sort(all(a));
    for(i=0;i<n;i++)p[i]=a[i].y;
    c[p[0]]=0;
    for(i=1;i<n;i++){
        if(a[i].x==a[i-1].x)c[p[i]]=c[p[i-1]];
        else c[p[i]]=c[p[i-1]]+1;
    }
    for(j=0;j<k;j++){
        vector<pair<pii,int>> arr(n);
        for(i=0;i<n;i++){
            arr[i]={{c[i],c[(i+(1<<j))%n]},i};
        }
        sort(all(arr));
        
        for(i=0;i<n;i++)p[i]=arr[i].y;
        c[p[0]]=0;
        for(i=1;i<n;i++){
            if(arr[i].x==arr[i-1].x)c[p[i]]=c[p[i-1]];
            else c[p[i]]=c[p[i-1]]+1;
        }
    }
    for(auto u: p)cout<<u<<' ';
    //free();   //if pointer array
    return 0;
}
