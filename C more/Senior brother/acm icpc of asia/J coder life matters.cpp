#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<set>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;
    bool code;
    cin>>test;
    while(test--){
            code = false;
        for(i=0,t=0;i<30;i++){
            scanf("%d",&k);
            if(k)t++;
            else t=0;
            if(t>5)code = true;
        }
        if(code)printf("#coderlifematters\n");
        else printf("#allcodersarefun\n");
    }

    //free();   //if pointer array
    return 0;
}
