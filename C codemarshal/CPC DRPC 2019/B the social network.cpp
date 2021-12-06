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
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
vi pa;

int dsu(int n){
    if(n==pa[n])return n;
    return pa[n]=dsu(pa[n]);
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    
    scanf("%d",&test);
    while(test--){
        scanf("%d %d",&n,&m);
        ordered_set st[n+1];
        pa.resize(n+1);
        
        for(i=1;i<=n;i++)pa[i]=i;
        printf("Case %d:\n",++t);
        while(m--){
            scanf("%d %d %d",&i,&j,&k);
            if(!i){
                int a=dsu(j),b=dsu(k);
                if(a!=b){
                    if(st[a].size()<st[b].size()) swap(a,b);
                    pa[b] = a;
                    //ranking[a]+=ranking[b];
                    for(auto &u: st[b])st[a].insert(u);
                }
            }
            else if(i==1){
                st[dsu(j)].insert(k);
            }
            else{
                int ans=0,last;
                scanf("%d",&last);
                j = dsu(j);
                if(!st[j].empty()) ans = st[j].order_of_key(last+1)-st[j].order_of_key(k);
                printf("%d\n",ans);
            }
        }
    }
    //free();   //if pointer array
    return 0;
}
