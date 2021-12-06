#include<bits/stdc++.h>
#define INF 10737414
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (bool)val&(1<<pos)
using namespace std;
///minimum palindrome partitioning

int mpp(string &a){
    //Base idea nirjhor27 vjudge
    int len=a.size(),palin[len+5],i,j;
    bool arr[1005][1005];
    for(i=0;i<=len;i++)arr[i][i]=arr[i+1][i]=true;
    for(j=1;j<len;j++){
        for(i=0;i+j<len;i++){
            arr[i][i+j]=(a[i]==a[i+j]) && arr[i+1][i+j-1];
        }
    }

    for(i=0;i<len;i++){
        if(arr[0][i]==true)palin[i]=0;///or use 1 for number of palindrome
        else{
            palin[i]=len;///maximum number of palindrome
            for(int k=0;k<i;k++){
                if(arr[k+1][i]==true && 1+palin[k]<palin[i])palin[i]=palin[k]+1;
            }
        }
    }
    ///minimum number of palindrome = minimum number of partition + 1
    return palin[len-1]+1;
}
int main(){

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    cin>>test;
    string s;
    while(test--){
        cin>>s;
        printf("Case %d: %d\n",++t,mpp(s));
    }
    //free();   //if pointer array
    return 0;
}
