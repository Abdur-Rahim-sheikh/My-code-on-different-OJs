#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

ll diamond[210][150];

void solve(int range){
    int p = 2*range,prev=2;
    for(int i=2;i<p;i++){
        int x = i-2*(i/range)*(i%range)+1;
        for(int j=1;j<x;j++){
            int k  = j + ((i-1)/range==0?-1:1);
            if(k>0 and k<prev and j<prev){
                diamond[i][j]+=max(diamond[i-1][j],diamond[i-1][k]);
            }
            else if(j<prev)diamond[i][j]+=diamond[i-1][j];
            else diamond[i][j]+=diamond[i-1][k];
            
        }
        prev=x;
    }
    
}
int main(){
    int test,i,j,n,t=0;
    cin>>test;
    while(test--){
        scanf("%d",&n);
        int p =2*n-1;
        ll val;
        for(i=1;i<=n;i++){
            for(j=1;j<=i;j++){
                scanf("%lld",&val);
                diamond[i][j]=val;
                
            }
        }
        for( ;i<=p;i++){
            for(j=1;j<=p-i+1;j++){
                scanf("%lld",&val);
                diamond[i][j]=val;
                
            }
        }
        
        solve(n);
        printf("Case %d: %lld\n",++t,diamond[2*n-1][1]);
    }
}
