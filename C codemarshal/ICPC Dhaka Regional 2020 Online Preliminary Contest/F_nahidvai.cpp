///Nahid Hasan Raju
#include <bits/stdc++.h>
#define ll long long
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define Fin freopen("input.txt","r",stdin)
using namespace std;

#define P(XX) cout<<XX<<endl
#define P1(XX) cerr<<"db1: "<<XX<<endl
#define P2(XX,YY) cerr<<"db2: "<<XX<<" "<<YY<<endl
#define P3(XX,YY,ZZ) cerr<<"db3: "<<XX<<" "<<YY<<" "<<ZZ<<endl
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Fout freopen("output.txt","w",stdout)
#define rep(i,a,b) for(i=a;i<=b;i++)
#define EPS 0.00000001
#define INF INT_MAX
#define PI 2*acos(0.0)
#define set(XX,POS) XX|=(1<<POS)
#define reset(XX,POS) XX&=(~(1<<POS))
#define check(XX,POS) (bool)(XX&(1<<POS))
#define toggle(XX,POS) (XX^(1<<POS))
#define SORT(v) sort(v.begin(),v.end())
#define REVERSE(V) reverse(v.begin(),v.end())
#define VALID(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define SIZE(ARRAY) sizeof(ARRAY)/sizeof(ARRAY[0])
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

#define MOD 1000000007ll
#define MX 2000006  ///200005

ll m, n;
ll a, b;
#define SZ 1000009
int pr[78600],in=0;
bool mr[SZ+3];

void sieve()
{
    int i,j,sq,p;
    sq=sqrt(SZ)+2;
    mr[1]=1;
    for(i=2; i<sq; i++){
        if(!mr[i]){
            for(j=i*i;j<=SZ;j+=i){
                mr[j]=1;
            }
        }
    }
    for(i=2; i<SZ; i++){
        if(!mr[i]){
            pr[++in] = i;
        }
    }
}


ll solve (ll n, ll r)
{
    vector<ll> vt;
    for(ll i=1; i<=in && pr[i]*pr[i]<=n; ++i){
        if (n % pr[i] == 0){
            vt.push_back (pr[i]);
            while (n % pr[i] == 0)
                n /= pr[i];
        }
    }
    if (n > 1)
        vt.push_back (n);

    ll sum = 0;
    for (ll chk=1; chk<(1<<vt.size()); ++chk)
    {
        ll mult = 1,
            tmp = 0;
        for (ll i=0; i<(ll)vt.size(); ++i)
            if (chk & (1<<i)) {
                ++tmp;
                mult *= vt[i];
            }

        ll cur = r / mult;
        if (tmp % 2 == 1)
            sum += cur;
        else
            sum -= cur;
    }
    return r - sum;
}



int main()
{
    int test=1, tc=0;
    ll i, j;
//Fin;
    ll k, ans, t, c, x, y, d, a1, a2;
    scanf("%d", &test);

    sieve();

    while(test--)
    {
       // vt.clear();
        ans=0;
        cin>>a>>b>>m;
        if(a>b)swap(a, b);
        d=b-a;

        a1=solve(d, a-1);
        a2=solve(d, a+m);

        ans=a2-a1;

        printf("Case %d: %lld\n", ++tc, ans);
    }
    return 0;
}
