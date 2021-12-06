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
int arr[1000005];
void lfs(string a){
    arr[0]=0;
    for(int i=1,j=0;i<a.size();i++){
        if(a[i]==a[j])arr[i]=++j;
        else{
            while(j>0 && a[i]!=a[j])j=arr[j-1];
            if(a[i]==a[j])arr[i]=++j;
            else arr[i]=0;
        }

    }
}
int main(){

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    string a,b;
    cin>>test;
    while(test--){
        cin>>a;
        b=a;
        reverse(a.begin(),a.end());
        lfs(a);

        for(i=0,j=0;i<b.size();i++){
             while(j>0 && a[j]!=b[i])j=arr[j-1];
             if(a[j]==b[i])j++;

        }

        printf("Case %d: %d\n",++t,2*a.size()-j);

    }
    //free();   //if pointer array
    return 0;
}
