#include<iostream>
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
char names[30],kTime;
bool inUse[30];
void permute(int i,int n){
    if(kTime==0)return;
    else if(i==n){
        names[i]='\0';
        printf("%s\n",names);
        kTime--;
        return;
    }
    for(int j=0;j<n;j++){
        if(inUse[j])continue;
        names[i]=j+'A';
        inUse[j]=true;
        permute(i+1,n);
        
        inUse[j]=false;
    }
    return;
}
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,sign;

    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
    scanf("%d %d",&n,&kTime);
    printf("Case %d:\n",++t);
    permute(0,n);
    }
    
    //free();   //if pointer array
    return 0;
}
