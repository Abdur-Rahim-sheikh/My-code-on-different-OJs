#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test;
   string str;
   char ch;
    cin>>n;
    for(j=0;j<n;j++){
        cin>>str;
        sort(str.begin(),str.end());
        val=str.length();
        ch=str[0];
        for(i=0;i+1<val;i++){
            if(str[i+1]==str[i+2])
                str[i+1]=ch;
        }
        sort(str.begin(),str.end());
        cout<<str<<endl;
    }

    //free();   //if pointer array
    return 0;
}


