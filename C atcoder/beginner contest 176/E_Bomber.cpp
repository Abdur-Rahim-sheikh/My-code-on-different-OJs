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
    int i,j,k,q,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n>>m>>q;
    vi row(n,0),col(m,0);
    vector<pii> arr(q);
    int maxa=0,maxb=0,cnta,cntb;
    for(i=0;i<q;i++){
        cin>>j>>k;
        j--;k--;
        row[j]++;
        col[k]++;
        if(row[j]==maxa)cnta++;
        else if(row[j]>maxa)maxa=row[j],cnta=1;
        
        if(col[k]==maxb)cntb++;
        else if(col[k]>maxb)maxb=col[k],cntb=1;

        arr[i]={j,k};
    }
    ll cnt=cnta*1ll*cntb;
    int ans=maxa+maxb;
    for(i=0;i<q;i++){
        int a=arr[i].x,b=arr[i].y;
        if(row[a]+col[b]==ans)cnt--;
    }

    if(cnt<=0)ans--;
    cout<<ans<<endl;
    //free();   //if pointer array
    return 0;
}
