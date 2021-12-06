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
int arr[25][5];
int solution[25][5];
int solve(int i,int j,int n){
    if(i==n)return 0;
    if(solution[i][j]!=0)return solution[i][j];
    int val=INF;
    for(int k=0;k<3;k++){
        if(k==j)continue;
        val=min(val,solve(i+1,k,n)+arr[i][j]);
    }
    return solution[i][j]=val;
}
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);

    cin>>test;

    while(test--){
        scanf("%d",&n);
        memset(solution,0,sizeof solution);

        for(i=0;i<n;i++)scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
        for(i=0;i<3;i++){
           solve(0,i,n);
        }
        int val=min(solution[0][1],min(solution[0][2],solution[0][0]));
        printf("Case %d: %d\n",++t,val);
    }



    //free();   //if pointer array
    return 0;
}
