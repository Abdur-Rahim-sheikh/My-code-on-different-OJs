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
// where is the prime in 2 to n and what(by index)
bool prime[10000];
void seive(int n)
{
	prime[1]=1;
	int j,k,i,number;
	number=sqrt(n)+1;
	for(i=2;i<=number;i++)
	{
		if(prime[i]>0)
		continue;

		for(j=i*i;j<=n;j+=i) if(prime[j]==0)prime[j]=true;
	}
}

int main(){
    int i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    n=sqrt(10000000)+1;
    seive(n);
    vector<int>primo;
    for(i=2;i<=n;i++)if(prime[i]==false)primo.pb(i);
    cin>>test;
    while(test--){
        scanf("%d %d",&m,&n);
        map<int,int> facto;
        for(i=0;primo[i]*primo[i]<=m;i++){
            cnt=0;
            while(m%primo[i]==0)cnt++,m/=primo[i];
            facto[primo[i]]=cnt;
        }
        if(m>1)facto[m]=1;
        int k=1,l;
        map<int,int> :: iterator it;
        int t=n;
        for(it=facto.begin();it!=facto.end();it++){
            cnt=0,l=1;
            int p=it->first;
            while(n%p==0)cnt++,n/=p,l*=p;
            //cout<<n<<' '<<m<<' '<<cnt<<' '<<facto[p]<<endl;
            if(cnt<facto[p])break;

            if(cnt==facto[p])k*=l;
        }

        if(it==facto.end())printf("%d\n",t/k);
        else printf("NO SOLUTION\n");
    }
    //free();   //if pointer array
    return 0;
}
