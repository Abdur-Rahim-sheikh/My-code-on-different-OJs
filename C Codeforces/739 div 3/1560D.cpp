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
bool prefix(string x,string pre){
    if(pre.size()>x.size())return false;
    int n = pre.size();
    for(int i=0;i<n;i++){
        if(x[i]!=pre[i])return false;
    }
    return true;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    map<string,bool> has;
    map<string,int> add;
    ll x = 1;
    for(i=0;i<64;i++){
        string tem = to_string(x);
        for(j=0;j<tem.size();j++){
            string sub = tem.substr(0,j+1);
            sub = to_string(atoi(sub.c_str()));
            if(has[sub]){
                add[sub]=min(add[sub],(int)(tem.size()-sub.size()));
            }
            else{
                // dbg(tem,j,sub);
                has[sub]=true;
                add[sub]=(int)(tem.size()-sub.size());
            }
        }
        x*=2;
    }
    
    cin>>test;
    while(test--){
        cin>>n;
        ll k = 0;
        ll tem = n;
        while(tem){
            tem/=10;
            k++;
        }
        string val = to_string(n);
        int len = val.size();
        int mini = len+1;
        for(ll mask=1;mask<(1<<k);mask++){
            string tem;
            for(j=0;j<k;j++){
                if(check(mask,j))tem+=val[j];
            }
            tem = to_string(atoi(tem.c_str()));
            int x = len-tem.size();
            // dbg(val,tem,x);
            if(has[tem]){
                // dbg(mini,x,add[tem],tem);
                mini = min(mini,x+add[tem]);

            }
        }
        // dbg(mini);
        printf("%d\n",mini);
    }
    //free();   //if pointer array
    return 0;
}
