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
#define on(val,pos) (val|(1<<pos))
#define off(val,pos) (val&(~(1<<pos)))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n;
    vector<vi> arr(2,vi(3));
    cin>>arr[0][0]>>arr[0][1]>>arr[0][2];
    cin>>arr[1][0]>>arr[1][1]>>arr[1][2];
    // maximum
    
    int maxi=0;
    for(i=0;i<3;i++){
        maxi+=min(arr[0][i],arr[1][(i+1)%3]);
    }
    int maxi2=0;
    vector<pii> permute(6);
    for(i=0;i<3;i++){
        permute[i]={i,i};
        permute[i+3]={i,(i+1)%3};
    }
    sort(all(permute));
    do{
        vector<vi> brr=arr;
        int sum=0;
        //dbg(permute,brr);
        for(auto u: permute){
            int x=min(brr[1][u.x],brr[0][u.y]);
            brr[1][u.x]-=x;
            brr[0][u.y]-=x;
            sum+=x;
        }
        maxi2=max(maxi2,sum);
    }while(next_permutation(all(permute)));
   
    //dbg(arr);
    
    cout<<n-maxi2<<' '<<maxi<<endl;
    //free();   //if pointer array
    return 0;
}
