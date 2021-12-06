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
int extgcd(int a,int b,int &x,int &y){
    if(a==0){
        x=0;
        y=1;
        return b;
    }
    int x1,y1;
    int gcd = extgcd(b%a,a,x1,y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}
int main(){
    int i,j,k,n,m,val,x,y;
    //freopen("000input.txt","r",stdin);
    fastIO
    cin>>n;
    vi arr(n);
    for(int &u:arr)cin>>u;
    if(n==1){
        cout<<"1 1\n0\n1 1\n0\n1 1\n"<<-arr[0]<<endl;
        return 0;
    }
    extgcd(n,n-1,x,y);
    x=-x;
    y=-y;
    cout<<"1"<<' '<<n<<endl;
    for(i=0;i<n;i++){
        cout<<arr[i]*1ll*n*x<<" \n"[i==n-1];
    }

    cout<<"2"<<' '<<n<<endl;
    for(i=1;i<n;i++){
        cout<<arr[i]*1ll*(n-1)*y<<" \n"[i==n-1];
    }

    cout<<"1 1\n"<<arr[0]*1ll*(n-1)*y<<endl;

    //free();   //if pointer array
    return 0;
}
