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
string dp[101][101];

void clean(int m,int n){
    for(int i=0;i<m;i++)dp[i][0]="";
    for(int i=0;i<n;i++)dp[0][i]="";
}

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    string str[2];
    while(test--){
        cin>>str[0]>>str[1];
        /// LCS print the lexicographically smallest one.
        m = str[0].size();
        n = str[1].size();
        clean(m,n);
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(str[0][i]==str[1][j])dp[i+1][j+1]=dp[i][j]+str[0][i];
                
                else if(dp[i][j+1].size()>dp[i+1][j].size())dp[i+1][j+1]=dp[i][j+1];
                else if(dp[i][j+1].size()<dp[i+1][j].size())dp[i+1][j+1]=dp[i+1][j];
                else if(dp[i][j+1]<dp[i+1][j])dp[i+1][j+1]=dp[i][j+1];
                else dp[i+1][j+1] = dp[i+1][j];
            }
        }
        printf("Case %d: ",++t);
        if(dp[m][n].size()==0)cout<<":("<<endl;
        else cout<<dp[m][n]<<endl;

        
    }
    //free();   //if pointer array
    return 0;
}
