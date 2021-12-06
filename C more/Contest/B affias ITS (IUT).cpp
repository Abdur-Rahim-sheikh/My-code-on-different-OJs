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
int arr[100002];

int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;
    cin>>n;

    vector<int> network[n+6];
    priority_queue<int,vector<int>,greater<int>> q;
    for(i=1;i<n;i++){
        scanf("%d %d",&j,&k);
        network[j].pb(k);
        network[k].pb(j);
        arr[j]++;
        arr[k]++;
    }
    for(i=1;i<=n;i++) if(arr[i]==1)q.push(i);
    int z= n-1;
    ll maxi =0;
    if(n==1){
         printf("0\n");
         return 0;
    }
    while(q.size()!=1){
        val = q.top();q.pop();
        maxi = max(maxi,(long long)val*z);

        k = network[val][0];

        arr[k]--;
        //cout<<val<<" "<<arr[k]<<' '<<k<<endl;
        if(arr[k]==1)q.push(k);


        vector<int>::iterator loc =find(network[k].begin(),network[k].end(),val);
        network[k].erase(loc);



        z--;
    }
   /// if(n==1) printf("0\n");

    printf("%lld\n",maxi);

    //free();   //if pointer array
    return 0;
}
