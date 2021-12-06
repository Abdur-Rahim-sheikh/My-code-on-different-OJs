#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;

int main()
{

    int i,j,k,m,n,val,cnt,test;
    int p,q,r,s,t,u;
    //freopen("000input.txt","r",stdin);
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u) == 6){
        double l=0.0,r=1.0,mid=1,ans;
        cnt=40;
        if((p * exp(-mid)) + (q * sin(mid)) + (r * cos(mid)) + (s * tan(mid) )+ t +u>1e-9 || u+r+p<0){
            printf("No Solution\n");
            continue;
        }
        while(cnt--){
            mid=(l+r)/2.00;
            ans = (p * exp(-mid)) + (q * sin(mid)) + (r * cos(mid)) + (s * tan(mid) )+ (t * mid *mid )+u;


            //if(fabs(ans) < 0.0001)break;
            if(ans>0)l=mid;
            else r = mid;
        }
        printf("%0.4lf\n",mid);
        //cout<<ans<<endl;
      //  if(fabs(ans)<0.0001)cout<<mid<<endl;
       // else printf("No Solution\n");
    }
    //free();   //if pointer array
    return 0;
}
