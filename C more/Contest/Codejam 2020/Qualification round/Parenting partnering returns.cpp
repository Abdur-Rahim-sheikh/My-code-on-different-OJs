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
    int s,e,ind;

    bool operator<(const st &x)const{
        if(x.e!=e)return e<x.e;
        else return s<x.s;
    }
};
bool comp(st a,st b){return a.ind<b.ind;}
int main(){
    int i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        st arr[n+5];
        char ch[n];
        ch[n]='\0';
        for(i=0;i<n;i++)scanf("%d %d",&arr[i].s,&arr[i].e),arr[i].ind=i;
        sort(arr,arr+n);
        //vector<pii> left;
        int tem1,tem2;

        tem1=tem2=0;
        for(i=0;i<n;i++){
            if(tem1<=arr[i].s)tem1=arr[i].e,ch[arr[i].ind]='C';
            else if(tem2<=arr[i].s)tem2=arr[i].e,ch[arr[i].ind]='J';
            else break;
        }

        printf("Case #%d: ",++t);
        if(i<n)printf("IMPOSSIBLE\n");
        else printf("%s\n",ch);


    }
    //free();   //if pointer array
    return 0;
}
