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
#define endl '\n'
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//replace less<int> to less_equal<int> to take duplicate values
const int sz=100005;
bool p[sz];
void fac(){
    for(int i=2;i*i<sz;i++){
        if(p[i])continue;

        for(int j=i*i;j<sz;j+=i){
            p[j]=true;
        }
    }
}


///always check once before submit
int segmentedSieve(int left,int right,vi &primo){
    vector<bool> prime(right-left+1);
	//if(left==1)prime[0]=true;
    for(int i=0;primo[i]*primo[i]<=right;i++){
        int k=primo[i];
        int base =(left/k)*k;
        if(base==0)base=2*k;
        if(base<left)base+=k;
        //cout<<base<<' '<<primo[i]<<endl;
        for(int j =base;j<=right;j+=k)prime[j-left]=true;
        if(base==k)prime[base-left]=false;
    }
    int cnt=0;
    for(int i=left;i<=right;i++)if(!prime[i-left])cnt++;
    return cnt;
}

int main(){
    int i,j,k,n,m,val,t=0,test,l,r;
    //freopen("000input.txt","r",stdin);
    fac();
    vi prime;
    for(i=2;i<sz;i++)if(!p[i])prime.pb(i);
    cin>>test;

    while(test--){
        cin>>l>>r;
        if((r-l)>100)cout<<"Yes"<<endl;
        else{
            int x = segmentedSieve(l,r,prime);
            if(x*3<(r-l+1))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }

    }
    //free();   //if pointer array
    return 0;
}
