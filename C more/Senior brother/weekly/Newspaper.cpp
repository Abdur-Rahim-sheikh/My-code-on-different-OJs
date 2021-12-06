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
    char ch;
    ll i,j,k,m,n,val,t=0,cnt=0,test;

    ll valu[500],cost[500];
    cin>>test;
    while(test--){
        for(i=0;i<150;i++){ valu[i]=0; cost[i]=0; }
        scanf("%lld",&n);
        getchar();
        for(i=0;i<n;i++){
            scanf("%c %lld%*c",&ch,&val);

            cost[ch]=val;
        }
        scanf("%lld",&k);
        string s;
        cin.ignore();
        while(k--){
            getline(cin,s);
            int len=s.length();
            for(j=0;j<len;j++)valu[s[j]]++;
        }
        double sum=0;
        for(j=30;j<150;j++)sum+=valu[j]*cost[j];
        //cout<<sum/100<<endl;
        printf("%0.2lf$\n",sum/100);
    }

    //free();   //if pointer array
    return 0;
}
