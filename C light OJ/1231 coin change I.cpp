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
        scanf("%d %d",&m,&n);
        int arr[m+2][n+2]={0};
        pii inf[m+5];
        for(i=0;i<=m;i++)arr[i][0]=1;
        for(i=1;i<=n;i++)arr[0][i]=0;

        for(i=1;i<=m;i++)  scanf("%d",&inf[i].first);
        for(i=1;i<=m;i++)  scanf("%d",&inf[i].second);
        //sort(inf+1,inf+m+1);
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                for(k=0,arr[i][j]=0;k<=inf[i].second;k++){
                    if(k*inf[i].first>j)break;

                    arr[i][j]=(arr[i][j]+arr[i-1][j-(k*inf[i].first)])%100000007;
                }
                //cout<<arr[i][j]<<' ';
            }
            //cout<<endl;
        }
        printf("Case %d: %d\n",++t,arr[m][n]);
    }
    //free();   //if pointer array
    return 0;
}
