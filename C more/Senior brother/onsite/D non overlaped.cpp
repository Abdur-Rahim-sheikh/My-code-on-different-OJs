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

    bool ab=false,ba=false;
    string s;
    cin>>s;
    int len=s.size();
    for(i=0;i<len-1;i++){
        if(s[i]=='A'  && s[i+1]=='B' && ab==false)ab=true,i++;
        else if(s[i]=='B'  && s[i+1]=='A' && ba==false)ba=true,i++;
    }

    if(ab==false || ba==false) ab=false,ba=false;
    if(ab==ba && ab==false)for(i=len-1;i>=0;i--){

        if(s[i]=='B' && s[i-1]=='A' && ab==false)ab=true,i--;

        else if(s[i]=='A' && s[i-1]=='B' && ba==false)ba=true,i--;
    }

    if(ab==false || ba==false)printf("NO\n");
    else printf("YES\n");
    //free();   //if pointer array
    return 0;
}
