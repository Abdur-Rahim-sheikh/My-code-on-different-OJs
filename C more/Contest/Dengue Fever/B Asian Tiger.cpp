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

int main(){

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        scanf("%d",&n);
        pii arr[n+5];
        for(i=0;i<n;i++)scanf("%d %d",&arr[i].second,&arr[i].first);
        sort(arr,arr+n);
        for(i=1,cnt=1;i<n;i++){
            int pos=arr[i-1].first;
            //cout<<pos<<' '<<arr[i].first<<endl;
            while(arr[i].second<pos && i<n)i++;
            if(i<n)cnt++;
        }
        printf("%d\n",cnt);
    }
    //free();   //if pointer array
    return 0;
}
