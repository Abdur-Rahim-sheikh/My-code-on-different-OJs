#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))

//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
const int MAX=(1<<16)+5;
// where is the prime in 2 to n and what(by index)
bool prime[MAX];
void seive(int n)
{
	int j,k,i,number;
	number=sqrt(n)+1;
	for(i=2;i<=number;i++)
	{
		if(prime[i]==true)
		continue;
		for(j=i*i;j<=n;j+=i) if(prime[j]==0)prime[j]=true;
	}
}

int main(){
    ll i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    seive(MAX-5);
    vector<ll> primo;
    for(i=2;i<=MAX-5;i++)if(prime[i]==false)primo.pb(i);
    cin>>test;
    while(test--){
        map<ll,ll> lcm;
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&val);
            for(j=0;primo[j]*primo[j]<=val;j++){
                cnt=0;
                while(val%primo[j]==0)cnt++,val/=primo[j];
                if(lcm[primo[j]]<cnt)lcm[primo[j]]=cnt;
            }
            if(val>1 and lcm[val]==0)lcm[val]=1;
        }
        map<ll,ll> :: iterator it;
        ll sum=1;
        for(it=lcm.begin();it!=lcm.end();it++){
            //cout<<it->first<<' '<<it->second<<endl;
            sum*=pow(it->first,it->second);
        }
        printf("%lld\n",sum);
    }
    //free();   //if pointer array
    return 0;
}
