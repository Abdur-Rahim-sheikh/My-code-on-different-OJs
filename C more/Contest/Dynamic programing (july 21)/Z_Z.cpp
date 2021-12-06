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
ll power10(ll x){
   ll ans=1;
    while(x--)ans*=10;
    return ans;
}
ll solve(string s){
    if(s=="-1")return 0;
    else if(s<="9" and s.size()==1)return 1;
    ll left=0,sum=0,right;
    for(int i=1;i<s.size();i++){
        left = left*10+s[i-1]-'0';
        right = s.size()-i-1;
        if(s[i]=='0'){
            sum+=(left-1)*power10(right);
            ll x=0;
            for(int j=i+1;j<s.size();j++)x=x*10+s[j]-'0';
            sum+=x+1;
        }
        else{
            sum+=left*power10(right);
        }
        // dbg(s[i],sum);
    }
    return sum+1;
}
int main(){
    ll i,j,k,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    string m,n;
    while(test--){
        cin>>val>>n;
        m = to_string(val-1); /// if val=0, then m="-1"
        // dbg(solve(m));
        // dbg(solve(n));
        printf("Case %lld: %lld\n",++t,solve(n)-solve(m));
    }
    //free();   //if pointer array
    return 0;
}
