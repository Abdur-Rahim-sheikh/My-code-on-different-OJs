#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;
vector<int>nextstep[100000];
int main()
{

    int i,j,k,m,n,val,t=0,test;
    string s;
    cin>>s;
    int len=s.length();
    bool same[10]={false};

    for(i=0;i<len;i++){
            int digit=s[i]-'0';
        if(same[digit]==true)nextstep[digit].push_back(i);
        if(digit>0 && digit<9){
            nextstep[digit].push_back(i);
            nextstep[digit].push_back(i+2);
        }


    }
    //free();   //if pointer array
    return 0;
}
