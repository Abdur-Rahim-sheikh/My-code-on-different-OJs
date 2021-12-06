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

    int i,j,k,m,n,val,t=0,cnt=0,test;

    string a,b;
    getline(cin,a);
    getline(cin,b);
    //cin>>a>>b;
    int len1=a.length();
    int len2=b.length();

    if(a==b)cout<<-1<<endl;
    else cout<<max(len1,len2)<<endl;

    //free();   //if pointer array
    return 0;
}
