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
string s[3];
int bit(int ind,int n){
    int x=0;
    for(int i=0;i<n;i++){
        x+=(s[ind]-'0')<<i;
    }
    return x;
}
bool match(int i,int j,int n){
    int a=(i&1)+(j&1);
    int tem=1;
    while(tem<n){
        int now=(on(i,tem)>0)+(on(j,tem)>0);
        if(!((now+a)&1))return false;
        a=now;
        tem++;
    }
    return true;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n>>m;
    string s[min(n,m)];
    char ch;
    getchar();
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
          scanf("%c",&ch);
          if(min(m,n)>3)continue;
          if(n<m)s[i]+=ch;
          else s[j]+=ch;
        }
        getchar();
    }
    if(n>m)swap(n,m);

    if(n==1)return printf("0\n"),0;
    else if(n>3)return printf("-1\n"),0;
    
    vvi dp((n<<1),vi(m));
    for(i=0;i<(1<<n);i++){
        int msk=bit(i,n);
        dbg(msk);
    }
    //free();   //if pointer array
    return 0;
}
