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

    int i,j,k,m,n,val,t=0,cnt,test,sum;

    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        scanf("%d",&n);
        printf("Case %d: ",++t);
        sum=cnt=0;
        for(i=0;i<n;i++){scanf("%d",&val);sum+=abs(val);if(val>0)cnt++;}
        if(!cnt)printf("inf\n");
        else{
            int k =__gcd(sum,cnt);
            printf("%d/%d\n",sum/k,cnt/k);
        }
    }
    //free();   //if pointer array
    return 0;
}
