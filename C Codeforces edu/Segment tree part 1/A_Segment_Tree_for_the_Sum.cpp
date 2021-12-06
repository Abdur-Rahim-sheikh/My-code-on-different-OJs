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
class seg_tree{
    ll *tree,*mini,*maxi;
    int low = -100000000;
    ///parameter
    ///update(1, 1, array_size, from_ind, to_ind, to_add_value)
    ///sum(1, 1, array_size, from_ind, to_ind,0)///last 0 for carry
public:
    seg_tree(int t){
        tree = new ll[4*t];
        //mini = new int[4*t];

        fill(tree,tree+(4*t),0);
    }
   void update(int i,int j,int x,int e,int ind=1,int b=0){
        if(b>j || e<i)return;
        else if(b>=i && e<=j){
            //mini[ind]+=x;
            tree[ind]=x;
            return;
        }

        int left=ind<<1;
        int right=left+1;
        int mid=(b+e)/2;
        update(i,j,x,mid,left,b);
        update(i,j,x,e,right,mid+1);
        tree[ind]=tree[left]+tree[right];
        //mini[ind]=min(mini[left],mini[right]);
    }
    ///always initial ind & b is 1 ,e is n && carry is 0
    ll sum(int i,int j,int e,int ind=1,int b=0){
        if(b>j || e<i)return 0;
        else if(b>=i && e<=j)return tree[ind];

        int left = ind<<1;
        int right =left+1;
        int mid=(b+e)/2;
        ll ans1 = sum(i,j,mid,left,b);
        ll ans2 = sum(i,j,e,right,mid+1);
        return ans1+ans2;
    }

    // int minimum(int i,int j,int e,int ind=1,int b=0){
    //     if(b>j || e<i)return INF;
    //     else if(b>=i && e<=j)return mini[ind];
    //     int left = ind<<1;
    //     int right = left+1;
    //     int mid = (b+e)/2;
    //     int ans1= minimum(i,j,mid,left,b);
    //     int ans2= minimum(i,j,e,right,mid+1);
    //     return min(ans1,ans2);
    // }

};

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n>>m;
    seg_tree tree = seg_tree(n);
    for(i=0;i<n;i++){
        cin>>val;
        tree.update(i,i,val,n-1);
    }

    for(i=0;i<m;i++){
        cin>>j>>k>>val;
        if(j==1)tree.update(k,k,val,n-1);
        else cout<<tree.sum(k,val-1,n-1)<<endl;
    }
    //free();   //if pointer array
    return 0;
}
