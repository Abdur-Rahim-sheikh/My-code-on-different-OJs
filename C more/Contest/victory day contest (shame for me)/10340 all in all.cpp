#include<bits/stdc++.h>

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define PI (2*acos(0.0))
#define on(x,i) (x|(1<<i))
#define check(x,i) (bool)(x&(1<<i))
#define ms(xx,yy) memset(xx,yy,sizeof xx)
using namespace std;
//int row[10]={-1,0,1,0,-1,1,1,-1};
//int col[10]={0,1,0,-1,1,1,-1,-1};

int main(){
    int i,j,k,m,n,test;
    //freopen("000input.txt","r",stdin);
    string a,b;
    while(cin>>a>>b){
        int n=b.size();
        int m=a.size();
        for(i=0,k=0;i<n;i++){
            if(a[k]==b[i])k++;
            if(k==m)break;
        }
        if(i<n)printf("Yes\n");
        else printf("No\n");
    }

    return 0;

}
