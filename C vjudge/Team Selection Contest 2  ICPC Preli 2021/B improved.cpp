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
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
vector<string> s;
int cnt,n,m;
vector<bool> alpha;
vector<int> starts,sum,add;
char find_alpha(){
    char ch;
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            ch=s[i][j];
            if(ch!='0' and alpha[ch-'A']==false){
                return ch;
            }
        }

    }
    return '0';
}

bool possible(){
    int rem=0;
    vi temsum=sum,temadd=add;
    for(int j=0;j<m;j++){
        rem=temadd[j]%10;
        temadd[j]/=10;
        if(temsum[j]!=temadd[j])return false;
        if(j<m-1)temadd[j+1]+=rem;
    }
    return rem==0;
}
void summation(char ch,int val){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]==ch){
                if(i==0)sum[j]+=val;
                else add[j]+=val;
            }
        }
    }
}
bool filled[10];
void solve(){
    char ch=find_alpha();
    if(ch=='0'){
        if(possible())cnt++;
        return;
    }
    alpha[ch-'A']=true;
    for(int i=0;i<10;i++){
        if(!filled[i]){
            filled[i]=true;
            summation(ch,i);
            solve();
            summation(ch,-i);
            filled[i]=false;
        }
    }
    alpha[ch-'A']=false;
}
int main(){
    int i,j,k,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n;
    s.resize(n);
    alpha.resize(26,false);
    starts.resize(n,0);
    m=0;
    for(i=n-1;i>=0;i--){
        cin>>s[i];
        m = max(m,(int)s[i].size());
    }
    //resizing now
    sum.resize(m,0);
    add.resize(m,0);
    for(i=0;i<n;i++){
        reverse(all(s[i]));
        starts[i]=s[i].size()-1;
        while(s[i].size()<m)s[i]+='0';
    }
    solve();
    cout<<cnt<<endl;
    //free();   //if pointer array
    return 0;
}
