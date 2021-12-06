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
    int l,d,u,r;
    l=d=u=r=0;
    char ch;
    cin>>n;
    getchar();
    while(n--){
        scanf("%c",&ch);
        if(ch=='D')d++;else if(ch=='L')l++;else if(ch=='R')r++;else u++;


    }
    printf("%d\n",2*(min(l,r)+min(u,d)));
    //free();   //if pointer array
    return 0;
}
