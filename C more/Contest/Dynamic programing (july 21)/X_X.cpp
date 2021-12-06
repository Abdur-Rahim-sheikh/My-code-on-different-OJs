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
vi arr,ans;
int cnt;
void solve(int left_to_fill,int available_digit,int have_to_fill){
    if(!left_to_fill){
        // dbg(ans);
        cnt++;
        return;
    }
    int ind,i;
    for(ind=0;ind<have_to_fill;ind++)if(ans[ind]==-1)break;
    for(i=0;i<available_digit;i++){
        // dbg(ans,arr[i],ind);
        if(ind>0 and abs(ans[ind-1]-arr[i])>2 and ans[ind-1]!=-1)continue;
        if(ind+1<have_to_fill and abs(ans[ind+1]-arr[i])>2 and ans[ind+1]!=-1)continue;
        ans[ind]=arr[i];

        solve(left_to_fill-1,available_digit,have_to_fill);
        ans[ind]=-1;
    }
}
int main(){
    int i,j,k,val,t=0,test,m,n;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>m>>n;
        arr.clear();
        arr.resize(m);
        for(int &u: arr)cin>>u;
        ans.clear();
        ans.resize(n,-1);
        // dbg(ans);
        cnt =0;
        solve(n,m,n);
        // dbg("done............");
        printf("Case %d: %d\n",++t,cnt);
    }
    //free();   //if pointer array
    return 0;
}
