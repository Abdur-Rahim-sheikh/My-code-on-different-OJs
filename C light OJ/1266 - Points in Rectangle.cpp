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
class BIT2D{
    int tree[1006][1006];
    int n,m;
public:
    BIT2D(int m,int n){
        this->m=m+5;
        this->n=n+5;
        memset(tree,0,sizeof tree);
    }
    void update(int x,int y,int val){
        while(x<=m){
            int k=y;
            while(k<=n){
                tree[x][k]+=val;
                k+= (k&-k);
            }
            x+=(x&-x);
        }
    }
    int sum(int x1,int y1,int x2,int y2){

        int sum=get(x2,y2);
        sum-=get(x2,y1-1);
        sum-=get(x1-1,y2);
        sum+=get(x1-1,y1-1);
        return sum;
    }
    int get(int x,int y){
        int sum=0;
        while(x>0){
            int k=y;
            while(k>0){
                sum+=tree[x][k];
                k-= (k&-k);
            }
            x-=(x&-x);
        }
        return sum;
    }
};
int main(){
    int i,j,k,n,m,t=0,p,q,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        BIT2D tree = BIT2D(1000,1000);

        cin>>n;
        printf("Case %d:\n",++t);
        map<pii,bool> spotted;
        for(i=0;i<n;i++){
            scanf("%d %d %d",&k,&m,&j);
            m++;j++;
            if(k){
                scanf("%d %d",&p,&q);
                p++;q++;
                printf("%d\n",tree.sum(m,j,p,q));
            }
            else if(!spotted[{m,j}])
                tree.update(m,j,1),spotted[{m,j}]=true;
        }
    }
    //free();   //if pointer array
    return 0;
}
