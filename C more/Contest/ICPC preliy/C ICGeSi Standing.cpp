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
struct sub{
    int solved,freez;
    int pen[100]={0};
};
int main(){
    int i,j,k,m,n,val,t=0,cnt,test,q;
    int a,b,c,d;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        sub arr[n+5];
        for(i=0;i<n;i++){
            scanf("%d %d %d %d",&a,&b,&c,&d);
            arr[a].solved=b;
            arr[a].pen[0]=c;
            arr[a].freez=d;
            for(j=1;j<=d;j++){
                scanf("%d",&arr[a].pen[j]);
                arr[a].pen[j]+=arr[a].pen[j-1];
            }
        }

        bool possible=true;
        scanf("%d",&val);
        int solved=arr[val].solved+arr[val].freez;
        int penalty=arr[val].pen[arr[val].freez];
        for(i=1;i<n;i++){
            scanf("%d",&val);
            int j,p,k=arr[val].freez;
            j=min(solved-arr[val].solved,k);
            //cout<<solved<<' '<<j<<' '<<arr[val].pen[j]<<endl;
            if(j>=0 && arr[val].pen[j]>=penalty){
                solved=arr[val].solved+j;
                penalty=arr[val].pen[j];
            }
            else if(j>0){
                solved=arr[val].solved+j-1;
                penalty=arr[val].pen[j-1];
            }

            else possible=false;

        }
        if(possible)printf("Case %d: We respect our judges :)\n",++t);
        else printf("Case %d: Say no to rumour >:\n",++t);

    }
    //free();   //if pointer array
    return 0;
}

