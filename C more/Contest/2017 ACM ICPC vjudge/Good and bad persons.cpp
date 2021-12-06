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

int main(){
    int i,j,k,m,n,val,t=0,cnt,test,q;
    //freopen("000input.txt","r",stdin);

    cin>>test;
    string tem,name[4]={"none","brother","chef","both"};

    while(test--){
        cin>>n>>m>>tem;
        int s=0,c=0;
        for(i=0;i<n;i++){
            if(tem[i]>='a')c++;
            else s++;
        }
        if(s>m && c>m)cout<<name[0]<<endl;
        else if(s<=m && c<=m)cout<<name[3]<<endl;
        else if(c<=m)cout<<name[1]<<endl;
        else cout<<name[2]<<endl;


    }
    //free();   //if pointer array
    return 0;
}
