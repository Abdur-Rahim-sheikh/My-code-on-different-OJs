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

    int i,j,k,m,n,val,t=0,cnt=0,test,arr[100]={0};

    cin>>n;
    string a;
    cin>>a;
    for(i=0;i<n;i++)  arr[a[i]]++;

    string name=arr['A']>arr['D']?"Anton":"Danik";
    if(arr['A']==arr['D'])name="Friendship";

    cout<<name<<endl;

    //free();   //if pointer array
    return 0;
}
