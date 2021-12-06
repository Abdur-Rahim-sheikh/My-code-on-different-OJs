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
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n>>k;
        vi brr(n);
        ll sum=0;
        for(auto &u: brr)cin>>u,sum+=u;
        
        vvi arr(2);
        for(i=0;i<n;i++){
            cin>>val;
            arr[val-1].pb(brr[i]);
        }
        if(sum<k){
            cout<<-1<<endl;
            continue;
        }
        sort(all(arr[0]),greater<int>());
        sort(all(arr[1]),greater<int>());

        dbg(arr[0],arr[1]);
        int cnt=0,i=0,j=0,ones=arr[0].size(),twos=arr[1].size();
        while(k>0){
            if(i<ones and arr[0][i]>=k){
                cnt++;
                k-=arr[0][i++];
            }
            else if(i+1<ones and j<twos and arr[0][i]+arr[0][i+1]<=arr[1][j]){
                cnt+=2;
                k-=arr[1][j++];
            }
            else if(i<ones and arr[0][i]>=arr[1][j]){
                cnt++;
                k-=arr[0][i++];
            }
            else{
                cnt+=2;
                k-=arr[1][j++];
            }
        }
        cout<<cnt<<endl;
    }
    //free();   //if pointer array
    return 0;
}
