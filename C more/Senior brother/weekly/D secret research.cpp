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

int main()
{

    int i,j,k,m,n,val,t=0,test;
    string experiment;
    cin>>test;
    while(test--){
        cin>>experiment;
        int len=experiment.length()-1;
        if(experiment=="1" || experiment=="4" || experiment=="78") printf("+\n");
        else if(experiment[len]=='5' && experiment[len-1]=='3')printf("-\n");
        else if(experiment[0]=='9' && experiment[len]=='4')printf("*\n");
        else if(experiment[0]=='1' && experiment[1]=='9' && experiment[2]=='0')printf("?\n");
    }
    //free();   //if pointer array
    return 0;
}
