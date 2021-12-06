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

    map<pair<int,int>,vector<pair<int,int> > >net;
    net[twoD(1,1)].push_back(twoD(1,2));
    cout<<net[twoD(1,1)].row<<' '<<net[twoD(1,1)].column<<endl;
    //free();   //if pointer array
    return 0;
}
