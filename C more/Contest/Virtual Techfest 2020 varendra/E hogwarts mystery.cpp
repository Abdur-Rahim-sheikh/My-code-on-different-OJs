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

int main(){
    int i,j,k,n,m,val,v,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n>>k>>v;
        vi arr(n+1),gre(n+1),greE(n+1);
        for(int i=1;i<=n;i++)cin>>arr[i];
        arr[0]=gre[0]=greE[0]=0;
        
        for(i=1;i<=n;i++){
            gre[i]=gre[i-1];
            greE[i]=greE[i-1];
            if(arr[i]>v)gre[i]++;
            if(arr[i]>=v)greE[i]++;
        }
        
        //dbg(gre,greE);
        for(i=1;i<=n;i++){
            int x = k-min(gre[i-1],k);
            int p=greE[i]+x-1;
            int mid,sum=i;
            for(mid=n/2;mid>0;mid=mid>>1){
                while((sum+mid)<=n and greE[sum+mid]<=p)sum+=mid;
            }
            //dbg(x,p,sum,i);
            cout<<sum-i+1<<' ';
        }
        cout<<endl;
    }
    
    //free();   //if pointer array
    return 0;
}
