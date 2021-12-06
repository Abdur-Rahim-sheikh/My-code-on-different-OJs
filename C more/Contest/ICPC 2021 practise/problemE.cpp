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
//replace less<int> to less_equal<int> to take duplicate values

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n;
    vi arr(n),brr(n+1,0);
    vector<bool> can(n,0);
    bool flag=false;
    int sum=0;
    for(i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        if(i==0 or i==n-1){
            if(arr[i]>1)flag=true;
        }
        if(arr[i]>2) flag = true;
    }
    if(flag){
        cout<<"NO"<<endl;
        return 0;
    }
    
    for(i=0;i<n;i++){
        
        if(arr[i]==0){
            if(brr[i])brr[i+1]=1;
        }
        else if(arr[i]==1){
            if(brr[i]==0)brr[i+1]=1;
        }
        else if(arr[i]==2){
            if(brr[i]==0)break;
            else brr[i+1]=1;
        }
    }
    
    if(i<n or brr[n]==1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    //free();   //if pointer array
    return 0;
}
