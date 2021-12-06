#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
const int sz = 10000007;
bool prime[sz];

void factorize(){
    for(int i=2;i*i<sz;i++){
        if(prime[i])continue;

        for(int j=i*i;j<sz;j+=i){
            prime[j]=true;
        }
    }
}
int main(){
    int t=0,cnt,test;
    ll i,val;
    factorize();
    vll primo;
    for(i=2;i<sz;i++)if(!prime[i])primo.push_back(i);
    //cout<<primo.back()<<endl;
    cin>>test;
    while(test--){
        scanf("%lld",&val);
        ll ans =1;
        while(val%2==0)val/=2;
        for(i=0;primo[i]*primo[i]<=val;i++){
            ll cnt=1;
            while(val%primo[i]==0){
                val/=primo[i];
                cnt++;
            }
            ans*=cnt;
        }
        if(val>1)ans*=2;
        printf("Case %d: %lld\n",++t,ans-1);
    }
    //free();   //if pointer array
    return 0;
}
