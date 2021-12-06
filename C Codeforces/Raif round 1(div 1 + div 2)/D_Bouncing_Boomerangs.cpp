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

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n;
    vi arr(n);
    for(auto &u:arr)cin>>u;
    vi cnt(4,0);
   
   bool flag=false;
    for(i=n-1;i>0;i--){
        cnt[arr[i]]=1;
        if(cnt[3]>0 and (cnt[2] + cnt[1])==0)flag=true;
        else if(cnt[2]>0 and cnt[1]==0)flag=true;
    }
    if(flag)return cout<<-1<<endl,0;

    
    int ind1=0,ind=0,row=1;
    vector<pii> sol;
    vi con(n,0);
    for(i=0;i<n;i++){
        if(arr[i]==0)continue;
        if(con[i]==0)sol.pb(row,i+1);
        if(arr[i]==1)row++;
        else if(arr[i]==2){
            ind1=max(ind1,i+1);
            while(arr[ind]==0 or con[ind]>0)ind++;
            
            sol.pb(row,i+1);
            sol.pb(row++,ones[ind]+1);
            if(arr[i]==3)sol.pb(row++)
        }
    }
    //free();   //if pointer array
    return 0;
}
