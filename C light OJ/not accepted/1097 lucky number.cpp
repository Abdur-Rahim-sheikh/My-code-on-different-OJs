#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define x first
#define y second
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))

//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
const int mx=1429500;//00
const int nx=100000;//000
class segtree{
    int tree[mx*4],i,j,ans[mx];

    void init(int ind=1,int b=1,int e=mx){
        if(b==e){
            if(b&1)tree[ind]=1;
            return;
        }

        int l=ind*2;
        int r=ind*2+1;
        int mid=(b+e)/2;
        init(l,b,mid);
        init(r,mid+1,e);
        tree[ind]=tree[l]+tree[r];
    }
    int query(int sum,int ind=1,int b=1,int e=mx){
        if(b==e)return b;
        int l=ind*2;
        int r=ind*2+1;
        int mid=(b+e)/2;
        if(tree[l]>=sum)return query(sum,l,b,mid);
        else return query(sum-tree[l],r,mid+1,e);

    }
    void update(int sum,int ind=1,int b=1,int e=mx){
        if(b==e){
            tree[ind]=0;
            return;
        }
        int l=ind*2;
        int r=ind*2+1;
        int mid=(b+e)/2;
        if(tree[l]>=sum) update(sum,l,b,mid);
        else update(sum-tree[l],r,mid+1,e);
        tree[ind]=tree[l]+tree[r];
        return;
    }

public:
    segtree(){
        memset(tree,0,sizeof tree);
        init();
    }
    int get(int i){return ans[i];}
    void solve(){
        ans[1]=1;
        for(int i=2;i<=nx;i++){
            ans[i]=query(i);

            for(int l=(mx/ans[i])*ans[i];l>0;l-=ans[i]){
                update(l);
            }
        }
    }

};
int main(){
    int i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    segtree tree =segtree();

    tree.solve();
    cin>>test;
    while(test--){
        cin>>n;
        printf("Case %d: %d\n",++t,tree.get(n));
    }
    //free();   //if pointer array
    return 0;
}
