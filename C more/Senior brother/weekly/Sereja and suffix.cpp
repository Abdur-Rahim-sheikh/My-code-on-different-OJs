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
    cin>>n>>m;
    int arr[n+5];
    for(i=1;i<=n;i++)scanf("%d",&arr[i]);
    map<int,bool>was;
    int total=0;
    for(i=n;i>0;i--){
        if(was[arr[i]]==true)arr[i]=total;
        else{
            was[arr[i]]=true;
            total++;
            arr[i]=total;
        }
    }
    for(i=0;i<m;i++){
        scanf("%d",&val);

        printf("%d\n",arr[val]);
    }



    //free();   //if pointer array
    return 0;
}
