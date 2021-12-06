#include<bits/stdc++.h>
#define ll long long
using namespace std;
//https://medium.com/@iamcrypticcoder/lightoj-1098-a-new-function-4bdce762287c
//If k*k=n then (n+k)=k * (k+1), (n+2*k) = k*(k+2)
//then from n to N (last number) there is k,k+1,k+2,.....N/k divisor's
// Let J= N - N%i
// and also (J - k*k)/k extra k divisor so there sum is
// (J - k*k)/k *k = (J - k*k) = k*(x - k) where k*x=J or x= J/k or N/k (integer division)
// So this combination happens for every k where 4<=k*k<=N
/// And these are all divisor from 1 to N

int main(){
	ll N,test,t=0;
	cin>>test;
	while(test--){
        cin>>N;
        ll sum=0;
        for(ll k=2;k*k<=N;k++){
            ll x = N/k;
            sum+=(x*(x+1))/2-(k*(k-1))/2;
            sum+=k*(x-k);
        }
        printf("Case %lld: %lld\n",++t,sum);
	}
	return 0;
}
