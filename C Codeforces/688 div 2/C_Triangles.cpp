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
vector<string> s;
pii rows(int ind,int x){
    int i,j;
    int n=s.size();
    char ch=x+'0';
    for(i=0;i<n;i++)if(s[ind][i]==ch)break;
    for(j=n-1;j>i;j--)if(s[ind][j]==ch)break;
    return {i,j};
}
pii cols(int ind,int x){
    int i,j;
    int n=s.size();
    char ch=x+'0';
    for(i=0;i<n;i++)if(s[i][ind]==ch)break;
    for(j=n-1;j>i;j--)if(s[j][ind]==ch)break;
    
    return {i,j};
}
struct st{
    int up,down,left,right;
};
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        s.resize(n);
        vector<st> arr(10);
        
        for(auto &u: s)cin>>u;
        
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                int p =s[i][j]-'0';
                arr[p].up=i;
                arr[p].down=min(arr[p].down,i);
                arr[p].right=max(j,arr[p].right);
                arr[p].left = min(j,arr[p].left);
            }
        }

        for(int x=0;x<10;x++){
            int ans =0;
            for(int i=0;i<n;i++){
                pii a = rows(i,x);
                if(a.x>a.y)continue;
                int l =max(arr[x].up-i-1,i-arr[x].down);
                int k = max(a.y,n-a.x-1);
                int p=max(i,n-i-1);
                ans =max(ans,(a.y-a.x)*p);
                ans = max(ans,l*k);
            }

            for(int i=0;i<n;i++){
                pii a = cols(i,x);
                if(a.x>a.y)continue;
                int l = max(arr[x].right-i-1,i-arr[x].left);
                int k = max(a.y,n-a.x-1);
                int p=max(i,n-i-1);
                ans =max(ans,(a.y-a.x)*p);
                ans = max(ans,l*k);
            }
            cout<<ans<<' ';
        }
        cout<<endl;

    }
    //free();   //if pointer array
    return 0;
}
