#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    ll i,j,k,m,n,val,test,arr[30],cnt=0;
    arr[0]=1;
    for(i=1;i<21;i++){
        arr[i]=arr[i-1]*i;
    }
    cin>>test;
    while(test--){
        string a;
        ll sum=1, alphabet[30]={0},t=0;
        cin>>a;
        int len=a.size();
        for(i=0;i<len;i++){
            alphabet[a[i]-'A']++;
        }
        for(i=0;i<26;i++){
            if(alphabet[i]>0){
                t+=alphabet[i];
                sum*=arr[alphabet[i]];
            }

        }
        printf("Data set %lld: %lld\n",++cnt,arr[t]/sum);
    }
    //free();   //if pointer array
    return 0;
}
