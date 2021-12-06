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
//row[4]={0,-1,0,1};
//col[4]={-1,0,1,0};
using namespace std;

int main(){
    int i,j,k,m,n,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    cin>>n;
    int arr[100005];
    memset(arr,0,sizeof arr);
    for(i=0;i<n;i++){
        scanf("%d",&val);
        arr[val]++;
    }
    int element=0;
    for(i=0;i<100005;i++){
        if(arr[i]>0){
            printf("%d number's frequency is %d\n",i,arr[i]);
            element++;
        }
    }
    printf("\nTotal different element are %d\n",element);
    //free();   //if pointer array
    return 0;
}
