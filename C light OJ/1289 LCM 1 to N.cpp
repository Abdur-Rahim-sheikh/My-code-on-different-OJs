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
#define MOD 4294967296
#define check(x,i) (x & (1<<i))
#define on(x,i) x=(x | (1<<i))
using namespace std;
const int MAX=(1e8)/32 + 1;
int prime[MAX];
vector<int> primo(5761455);
void sieve(int n){
    for(int i=2;i*i<n;i++){
        if(check(prime[i/32],i%32))continue;
        for(int j=i*i;j<n;j+=i){
            on(prime[j/32],j%32);
        }
    }
}
int main(){
    int i,j,k,m,n,val,t=0,cnt=0,test;
    sieve(100000000);
    for(i=2;i<100000000;i++)if(!check(prime[i/32],i%32))primo[cnt++]=i;
    unsigned int mult[5761457];
    mult[0]=2;
    for(i=1;i<cnt;i++)mult[i]=(mult[i-1]*primo[i]);
    cin>>test;
    while(test--){
        cin>>n;
        unsigned int ans=1;
        for(i=0;primo[i]*primo[i]<=n;i++){
            int tem=n/primo[i];
            while(tem>=primo[i]){
                tem/=primo[i];
                ans=(ans*primo[i])%MOD;
            }
        }
        int k=upper_bound(primo.begin(),primo.end(),n)-primo.begin();
        //cout<<ans<<' '<<k<<' '<<mult[k-1]<<endl;
        ans = (ans * mult[k-1]);
        cout<<"Case "<<++t<<": "<<ans<<endl;
    }
    //free();   //if pointer array
    return 0;
}
