#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test;

    string a;
    cin>>test;
    while(test--){
        cin>>a;
        int len=a.length(),sum=0;
        for(i=0;i<len;i++){
            sum+=a[i]-'0';
        }
        printf("%d\n",sum);
    }
    //free();   //if pointer array
    return 0;
}
