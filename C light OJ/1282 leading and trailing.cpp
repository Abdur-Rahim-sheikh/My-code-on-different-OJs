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
int last_three(int n,int k);
int first_three(int n,int k);
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;


    cin>>test;
    while(test--){
        scanf("%d %d",&n,&k);
        int last  = last_three(n,k);
        int first = first_three(n,k);

        printf("Case %d: %d %03d\n",++t,first,last);///%03d denotes if last is less then 3 then it will occupy leading zero
    }

    //free();   //if pointer array
    return 0;
}

int last_three(int n,int k){
    int base=n%1000,ans=1;
    ///now we will iterate mode of base k time
    while(k){
        if(k&1)ans=(ans*base)%1000;

        base=(base*base)%1000;
        ///as doubled the base half the iteration quick process
        k=k>>1;
    }
    return ans;
}
int first_three(int n,int k){
    ///the number is n^k
    int p =floor(k*log10(n))+1;
     int ans =pow(10,(k*log10(n)-p))*1000;
     return ans;

}
