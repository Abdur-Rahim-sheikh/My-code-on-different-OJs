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
    cin>>test;
    string s;
    while(test--){
        cin>>n>>s;
        vi right(n,1),left(n,1);
        
        for(i=1;i<n;i++){
            if(s[i-1]!=s[i])left[i]+=left[i-1];
        }

        for(i=n-2;i>=0;i--){
            if(s[i+1]!=s[i])right[i]+=right[i+1];
        }
        vi ans(n+1,1);
        //dbg(left,right);
        for(i=0;i<n-1;i++){
            if(s[i]=='L')ans[i+1]+=left[i];
            if(s[i+1]=='R')ans[i+1]+=right[i+1];
        }
        if(s[0]=='R')ans[0]+=right[0];
        if(s[n-1]=='L')ans[n]+=left[n-1];

        for(int u: ans)cout<<u<<' ';
        cout<<endl;

        
    }
    //free();   //if pointer array
    return 0;
}
