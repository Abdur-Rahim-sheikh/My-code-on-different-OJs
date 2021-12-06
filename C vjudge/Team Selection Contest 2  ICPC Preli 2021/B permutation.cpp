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
int n,m,cnt;
vi starts,beta;
map<char,int> alpha;
int perm[10];
bool possible(){
    vi add(m,0),sum(m,0);
    //dbg(perm[0],perm[2]);
    int rem=0;
    for(int j=0;j<m;j++){
        add[j]=rem;
        for(int i=0;i<n;i++){
            char ch = s[i][j];
            if(ch=='0')continue;
            if(starts[i]==j and perm[alpha[ch]]==0)return false;
            if(i)add[j]+=perm[alpha[ch]];
            else sum[j]=perm[alpha[ch]];
        }
        rem=(add[j])/10;
        add[j]=add[j]%10;
        if(sum[j]!=add[j])return false;
    }
    return rem==0;
}
bool taken[10];
void solve(auto it){
    dbg(it->x,it->y);
    if(it==alpha.end()){
        if(possible())cnt++;
        return;
    }
    for(int i=0;i<10;i++){
        if(!taken[i]){
            taken[i]=true;
            perm[it->y]=i;
            solve(it++);
            taken[i]=false;
        }
    }
}
int main(){
    int i,j,k,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n;
    s.resize(n);
    
    m=0;
    
    for(i=n-1;i>=0;i--){
        cin>>s[i];
        for(auto &u:s[i]){
            if(!alpha[u])alpha[u]=++t;
        }
        m = max(m,(int)s[i].size());
    }
    if(t>10){
        printf("0\n");
        return 0;
    }
    for(auto &it: alpha){
        it.y--; 
    }
    starts.resize(n);
    for(i=0;i<n;i++){
        reverse(all(s[i]));
        starts[i]=s[i].size()-1;
        while(s[i].size()<m)s[i]+='0';
    }
    //dbg(m);
    //permute
    cnt=0;
    //for(i=0;i<10;i++)perm[i]=i;

    // do{
    //     if(possible()){
    //         cnt++;
    //         for(auto u: alpha){
    //             printf("(%c,%d) ",u.x,perm[u.y]);
    //         }
    //         cout<<endl<<cnt<<endl;
    //     }
    // }while(next_permutation(perm,perm+10));

    solve(alpha.begin());
    cout<<cnt<<endl;
    //free();   //if pointer array
    return 0;
}
