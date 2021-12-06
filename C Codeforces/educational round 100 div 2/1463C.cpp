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
int direction(int prev, int dest){
    if(dest>prev)return 1;
    else if(dest<prev)return -1;
    else return 0;
}

int range(int x,int y,int p){
    if(x>y)swap(x,y);
    if(x<=p and p<=y)return 1;
    else return 0;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        vector<pii> arr(n);
        for(auto &u: arr){
            cin>>u.x>>u.y;
        }
        arr.pb({INF,0});
        int prev=0,dest=arr[0].y,dir=direction(prev,dest),cur;
        int cnt=0;
        for(i=1;i<=n;i++){
            if(abs(prev-dest)<=arr[i].x-arr[i-1].x){
                cur = dest;
                dest= arr[i].y;
                dir = direction(cur,dest);
            }
            else{
                cur = prev + dir*(arr[i].x-arr[i-1].x);
            }
            cnt+=range(prev,cur,arr[i-1].y);
            prev = cur;
        }
        cout<<cnt<<endl;
    }
    //free();   //if pointer array
    return 0;
}
