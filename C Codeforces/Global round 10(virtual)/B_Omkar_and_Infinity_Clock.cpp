#include<bits/stdc++.h>

#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define p1(n) printf("showing %d\n",n)
#define p2(m,n) printf("showing %d %d\n",m,n)
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
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
    ll i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n>>m;
        vector<ll>arr(n);
        k=-INF;
        for(i=0;i<n;i++){cin>>arr[i];k=max(k,arr[i]);}
        //k=max_element(all(arr));
        vector<ll> maxi;
        maxi.pb(k);
        for(i=0;i<m;i++){
            ll tem=-INF;
            for(j=0;j<n;j++){
                arr[j]=k-arr[j];
                tem=max(arr[j],tem);
            }
            k=tem;
            if(i>0 and maxi[maxi.size()-2]==k)break;
            maxi.pb(k);
        }
        if(i<m and (m-i-1)&1)for(i=0;i<n;i++)arr[i]=k-arr[i];
        for(i=0;i<n;i++)printf("%d ",arr[i]);
        cout<<endl;
    }
    //free();   //if pointer array
    return 0;
}
