#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"d2 "<<X<<" "<<Y<<endl;
#define P3(X,Y,Z) cout<<"d3 "<<X<<" "<<Y<<" "<<Z<<endl;
#define SQ(x) ((x) * (x))

#define ll long long
#define pii pair<int,int>

#define bchk(n,i) (bool)(n&(1<<i))
#define bon(n,i) (n|(1<<i))
#define boff(n,i) n=n&(~(1<<i))

#define distance(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define MAX3(a,b,c) max(a,max(b,c))
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define FastIO ios_base::sync_with_stdio(0);cin.tie(nullptr);
#define eps 10e-9
#define MX 1000005
#define MD 1000000007

using namespace std;
ll m,n;
int main()
{
    ll i,j,test=1,cas=0;
    ll a,b,r,an;
	#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
	#endif
	double d,givA,fullA,remA,pi=2*acos(0.0);
    scanf("%lld",&test);
    while(test--){
        scanf("%lld %lld %lld %lld ",&a,&b,&r,&an);
        d=SQ(r+a)+SQ(b);
        d=sqrt(d);
        double sd,ld,res;
        givA= an/180.0 *pi;
        fullA = acos((a+r)/d);
        if(fullA<=givA){
            printf("%lf\n",d-r);
            continue;
        }
        remA=fullA -givA;
        sd = r/cos(remA) ;
        ld=d-sd;
        res= cos(remA)*ld;
        printf("%lf\n",res);
    }
    return 0;
}