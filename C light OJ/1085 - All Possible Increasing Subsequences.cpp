#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))

//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
const int mod=1000000007;
class BIT{
     int n;///sum function returns long long
    int *arr;
public:
    BIT(int total){
        arr = new int[total+5];
        n = total;
        fill(arr,arr+total+5,0);
    }

    void update(int i,int x){
        while(i<=n){
            arr[i]=(arr[i]+x)%mod;
            i+=(i&-i);
        }
    }
    ll sum(int i,int j){
        ll sum[2]={0},it=2,init[2]={i-1,j};//so init[0]=i-1,and init=[1]=j
        while(it--){
            int r=init[it];
            while(r>0){
                sum[it]=(sum[it]+arr[r]+mod)%mod;
                r-=(r&-r);
            }
        }
        return sum[1]-sum[0];
    }

};
int main(){
    int i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        BIT tree = BIT(n);
        int arr[n+5];
        map<int,int> maped;
        for(i=0;i<n;i++)scanf("%d",&arr[i]),maped[arr[i]]=1;
        map<int,int>:: iterator it;
        for(it=maped.begin(),i=1;it!=maped.end();it++){
            it->second=i++;
        }
        for(i=0;i<n;i++){
            val=maped[arr[i]];
            ll sum=(1+tree.sum(0,val-1))%mod;
            tree.update(val,sum);
        }
        printf("Case %d: %lld\n",++t,tree.sum(0,n));
    }
    //free();   //if pointer array
    return 0;
}
