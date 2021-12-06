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
int tree[303][3003],m;
void update(int i,int j,int val){
    while(j<=m){
        tree[i][j]+=val;
        j+=(j&-j);
    }
}
double get(int i){
    int j=m;
    double sum=0;
    while(j>0){
        sum+=tree[i][j];
        j-=(j&-j);
    }
    return sum;
}
int main(){
    int i,j,k,n,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    map<int,int> these;

    cin>>n>>m;
    int mine[n+5];
    int arr[n+5][m+5];
    for(i=0;i<n;i++){
        int sum=0,mx=0,save;
        for(j=1;j<=m;j++){
            scanf("%d",&val);
            update(i,j,val);
            if(val>mx){
               mx=val;
               save=j;
            }
            arr[i][j]=val;
        }
        these[mx]++;
        mine[i]=save;
    }
    double ans=0;
    for(i=0;i<n;i++){
        ans+=get(i)/1000.00;
        cout<<ans<<endl;
        k=mine[i];
        these[k]--;
        if(these[k]==0){
                Hare;
            for(j=i+1;j<n;j++)if(arr[j][k])update(j,k,-arr[j][k]);
        }
    }
    printf("%0.9lf\n",ans);

    //free();   //if pointer array
    return 0;
}
