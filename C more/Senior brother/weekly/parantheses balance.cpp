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

    int i,j,k,m,n,val,t=0,cnt=0,test,total;

    cin>>test;
    while(test--){
        string s,store;
        cin>>s;
        int len=s.length();
        for(i=0,total=0;i<len;i++){
            if(s[i]=='(' || s[i]=='[')store[total++]=s[i];
            else if(total>0){
                if(s[i]==')' && store[total-1]=='(')total--;
                else if(s[i]==']' && store[total-1]=='[')total--;
                else break;
            }
            else break;
        }
        if(i<len)printf("No\n");
        else printf("Yes\n");
    }

    //free();   //if pointer array
    return 0;
}
