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

    string str,sub,tem;
    while(getline(cin,str) && str!=""){
        int len =str.size();

        for(i=0;i<len;i++){
            j=len-1;
            k=i;
            while(k<=j){
                if(str[k]!=str[j])break;
                k++;
                j--;
            }
            if(k>j)break;
        }
        sub="";
       if(i>0)sub=str.substr(0,i);
       reverse(sub.begin(),sub.end());
       str+=sub;
        printf("%s\n",str.c_str());
    }
    //free();   //if pointer array
    return 0;
}
