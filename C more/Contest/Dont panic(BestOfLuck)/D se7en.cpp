#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (bool)val&(1<<pos)
using namespace std;
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
            arr[i]+=x;
            i+=(i&-i);
        }
    }
    int sum(int i){
        int sum=0;
        while(i>0){
            sum+=arr[i];
            i-=(i&-i);
        }
        return sum;
    }

};
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;

    freopen("000input.txt","r",stdin);

    cin>>test;

    while(test--){
        scanf("%d %d",&n,&m);
        pii arr[n+5];
        int point[m+5];
        map<int,int>hashed;
        map<int,int>:: iterator it;
        for(i=0;i<n;i++){
            scanf("%d %d",&arr[i].first,&arr[i].second);
            hashed[arr[i].first]=1;
            hashed[arr[i].second]=1;
        }
        for(i=0;i<m;i++){
            scanf("%d",&point[i]);
            hashed[point[i]]=1;
        }
        int len=hashed.size();
        BIT bit= BIT(len);
        for(it=hashed.begin(),i=1;it!=hashed.end();it++,i++)
            hashed[it->first]=i;

        for(i=0;i<n;i++){
            bit.update(hashed[arr[i].first],1);
            bit.update(hashed[arr[i].second]+1,-1);
        }
        printf("Case %d:\n",++t);
        for(i=0;i<m;i++){
            printf("%d\n",bit.sum(hashed[point[i]]));
        }
    }
    //free();   //if pointer array
    return 0;
}
