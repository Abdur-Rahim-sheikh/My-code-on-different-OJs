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
    string tem;
    cin>>test;
    while(test--){
        int arr[4]={0};
        cin>>n;
        for(i=0;i<n;i++){
            cin>>tem;
            if(tem=="a" || tem=="aa")arr[0]++;
            else if(tem=="b" || tem=="bb")arr[1]++;
            else if(tem=="ab")arr[2]++;
            else arr[3]++;
        }

        int mini=min(arr[2],arr[3]);
        int maxi=max(arr[2],arr[3]);
        if(maxi)cout<<(maxi*2)+(maxi==mini)<<endl;
        else cout<<(arr[0]>0)+(arr[1]>0)<<endl;

    }
    //free();   //if pointer array
    return 0;
}
