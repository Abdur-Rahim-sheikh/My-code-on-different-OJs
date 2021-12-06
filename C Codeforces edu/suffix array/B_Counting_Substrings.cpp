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
void countSort(vi &p,vi &c){
    int n=p.size(),i;
    vi cnt(n,0),bucket(n);
    for(int u: c) cnt[u]++;

    bucket[0]=0;
    for(i=1;i<n;i++)bucket[i]=bucket[i-1]+cnt[i-1];
    
    vi pNew(n);
    for(auto x: p){
        int u=c[x];
        pNew[bucket[u]]=x;
        bucket[u]++;
    }
    p.swap(pNew);
}
vi suffixArray(string s){
    int i,n;
    s+='$';
    n=s.size();

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
    int k=0;
    while((1<<k)<n){
        for(i=0;i<n;i++) p[i]=(p[i]-(1<<k)+n)%n;
        
        countSort(p,c);
        vi cNew(n);
        
        cNew[p[0]]=0;
        for(i=1;i<n;i++){
            pii prev={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
            pii now={c[p[i]],c[(p[i]+(1<<k))%n]};

            if(prev==now)cNew[p[i]]=cNew[p[i-1]];
            else cNew[p[i]]=cNew[p[i-1]]+1;
        }
        c.swap(cNew);
        k++;
    }
    return p;
}
vi p;
string s,tem;
int bin(bool upper=false){
    int lo=0;
    int m=s.size();
    int mid=m;
    while(mid){
        while(lo+mid<=m){
            int len=min(m-p[lo+mid],(int)tem.size());
            int x=tem.compare(s.substr(p[lo+mid],len));
            
            if(upper and x>=0)lo+=mid;
            else if(!upper and x>0)lo+=mid;
            else break;
         }
         mid=mid>>1;
            
    }
    return lo;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>s>>n;
    
    p=suffixArray(s);
    for(i=0;i<n;i++){
        cin>>tem;
        cout<<bin(true)-bin()<<endl;
    }
    //free();   //if pointer array
    return 0;
}
