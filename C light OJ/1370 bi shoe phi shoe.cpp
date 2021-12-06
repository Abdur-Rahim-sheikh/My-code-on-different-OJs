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
#define x first
#define y second
const int MAX=1000004;
using namespace std;
bool check[MAX];

void prime_factory(int n);
int main(){
    int i,j,k,m,n,val,t=0,cnt,test;

    prime_factory(MAX);

   vector<int>primo;
   for(i=2;i<MAX;i++)if(check[i]==false)primo.pb(i);
    cin>>test;

    while(test--){
        scanf("%d",&n);
        ll sum=0;
        for(i=0,sum=0;i<n;i++){
            scanf("%d",&val);
            sum+=*upper_bound(primo.begin(),primo.end(),val);

        }
        printf("Case %d: %lld Xukha\n",++t,sum);
    }

    //free();   //if pointer array
    return 0;
}

// where is the prime in 2 to n and what(by index)
void prime_factory(int n){
	for(int i=2;i*i<n;i++){
		if(check[i]) continue;
		for(int j=i*i;j<n;j+=i) check[j]=true;
	}
}

