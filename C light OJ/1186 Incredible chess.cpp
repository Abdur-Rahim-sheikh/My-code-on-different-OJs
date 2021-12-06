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

int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);

    cin>>test;

    while(test--){
        scanf("%d",&n);
        int arr[n+5];
        for(i=0;i<n;i++)scanf("%d",&arr[i]);
        scanf("%d",&val);
        int sum=abs(val-arr[0])-1;
        for(i=1;i<n;i++){
            scanf("%d",&val);
            sum^=(abs(val-arr[i])-1);

        }
        if(sum)printf("Case %d: white wins\n",++t);
        else printf("Case %d: black wins\n",++t);
    }



    //free();   //if pointer array
    return 0;
}
