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

//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
struct st{
    int x,y,ind;
    bool operator<(st &tem)const{
        return x<tem.x;
    }
};
int main(){
    int i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;

        char ch[n];
        ch[n]='\0';
        st arr[n];
        for(i=0;i<n;i++)scanf("%d %d",&arr[i].x,&arr[i].y),arr[i].ind=i;
        sort(arr,arr+n);
        for(i=0;i<(1<<n);i++){
            int tem1=0,tem2=0;
            for(j=0;j<n;j++){
                if(i&(1<<j)){
                    //p1(j);
                    if(tem1>arr[j].x)break;
                    tem1=arr[j].y;
                    ch[arr[j].ind]='J';
                }
                else{
                    if(tem2>arr[j].x)break;
                    tem2=arr[j].y;
                    ch[arr[j].ind]='C';
                }
            }
            if(j==n) break;
        }
        printf("Case #%d: ",++t);
        if(i==(1<<n))printf("IMPOSSIBLE\n");
        else printf("%s\n",ch);


    }
    //free();   //if pointer array
    return 0;
}
