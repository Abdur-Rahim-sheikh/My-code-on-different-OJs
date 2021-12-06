#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))

//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
class BIT{

    int n;///sum function returns long long
    int *arr;
public:
    BIT(int total){
        arr = new int[total+5];
        n = total;
        memset(arr,0,sizeof arr);
    }

    void update(int i,int x){
        while(i<=n){
            arr[i]+=x;
            i+=(i&-i);
        }
    }
    ll sum(int r){
        ll sum=0;//so init[0]=i-1,and init=[1]=j

        while(r>0){
            sum+=arr[r];
            r-=(r&-r);
        }

        return sum;
    }

};
int main(){
    int i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        scanf("%d",&n);
        BIT tree =BIT(10000000);
        ll sum=0;
        for(i=0;i<n;i++){
            scanf("%d",&val);

            sum+=i-tree.sum(val);
            tree.update(val,1);
        }
        printf("%lld\n",sum);
    }
    //free();   //if pointer array
    return 0;
}
