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

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n>>m;
        vvi arr(n+1);
        vi edges(n+1,0);
        // special case
        if(n==1){
            printf("0\n");
            continue;
        }
        for(i=1;i<n;i++){
            cin>>j>>k;
            arr[j].pb(k);
            arr[k].pb(j);
            edges[j]++;
            edges[k]++;
        }
        vi leaf,tem;
        for(i=1;i<=n;i++)if(edges[i]==1)tem.pb(i);
        
        // dbg(edges,tem);
        int ans=0;
        for(i=0;i<m;i++){
            ans+=tem.size();
            // dbg(i,ans,tem);
            swap(tem,leaf);
            tem.clear();
            // if there is no leaf, no need the loop
            if(leaf.size()==0)break;

            while(!leaf.empty()){
                int x = leaf.back();
                leaf.pop_back();
                edges[x]=0;
                for(int u: arr[x]){
                    if(!edges[u])continue;
                    edges[u]--;

                    if(edges[u]==1)tem.pb(u);
                }
            }
        }

        cout<<n-ans<<endl;
    }
    //free();   //if pointer array
    return 0;
}
