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

    int i,j,k,m,n,val,t=0,cnt=0,test,arr[30]={0};

    cin>>n>>k;
    char ch;
    getchar();
    for(i=0;i<n;i++){
        scanf("%c",&ch);
        arr[ch-'a']++;
        //cout<<arr[ch-'a']<<endl;
        if(arr[ch-'a']>k)t=1;
    }
    printf("%s\n",t>0?"NO":"YES");
    //free();   //if pointer array
    return 0;
}
