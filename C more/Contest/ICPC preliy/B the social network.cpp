#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (bool)(val&(1<<pos))
using namespace std;
int parent[100005];
vector<ll>query[300005];
map<ll,int> myMap;
map<int,int>papa;
map<ll,int>:: iterator it;
class BIT{

    int n,k;///sum function returns long long
    int *arr;
public:
    BIT(int total){
        arr = new int[total+5];

        fill(arr,arr+total+5,0);
    }

    void update(int i,int x){
        while(i<=n){
            arr[i]+=x;
            i+=(i&-i);
        }
    }
    ll sum(int k,int i,int j){
        ll sum[2]={0},it=2,init[2]={i-1,j};//so init[0]=i-1,and init=[1]=j
        while(it--){
            int r=init[it];
            while(r>0){
                sum[it]+=arr[r];
                r-=(r&-r);
            }
        }
        return sum[1]-sum[0];
    }

};
int find_parent(int i){
    if(parent[i]==i)return i;
    return parent[i]=find_parent(parent[i]);
}

void solve(int n,int q);
int main(){

    fastIO
    int i,j,k,m,n,val,t=0,cnt,test,q;
    ll sign,a,b,c;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        scanf("%d %d",&n,&q);
        for(i=1;i<=n;i++)parent[i]=i;

        myMap.clear();
        for(i=0;i<q;i++){
            scanf("%lld %lld %lld",&sign,&a,&b);
            query[i].pb(sign),query[i].pb(a),query[i].pb(b);

            if(sign==2)scanf("%lld",&c),query[i].pb(c);
            myMap[a]=myMap[b]=myMap[c]=1;
            if(sign==0){
                int x=find_parent(a);
                int y=find_parent(b);
                if(x!=y)parent[x]=y;
            }

        }
        for(it=myMap.begin(),cnt=1;it!=myMap.end();it++,cnt++)
            it->second=cnt;
        for(i=1,cnt=0;i<=n;i++){
            int p=find_parent(i);
            if(papa[p]==0)papa[p]=cnt++;
        }
        solve(cnt,q);
        for(i=0;i<q;i++)query[i].clear();
    }
    //free();   //if pointer array
    return 0;
}

void solve(int n,int q){
    BIT tree[n]=BIT(q);
    int len=query.size();
    for(i=0;i<len;i++){
        if(query[i][0]==)
    }

}
