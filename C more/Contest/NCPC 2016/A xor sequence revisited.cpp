#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main()
{
    ll k,test,a,b;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--)
    {
        cin>>a>>b;
        if((b-a)>=3)
            printf("0\n");
        else if(a==0 and a==b)
            printf("1\n");
        else if(a==0)
            printf("0\n");
        else
        {
            ll ans=(1LL<<50)-1,m=4;
            while(a<=b)
            {
                k=(a-1)%m;
                if(k==1)
                    ans=ans&a;
                else if(k==2)
                    ans=ans&1;
                else if(k==3)
                    ans=ans&(a+1);
                else
                    ans=0LL;
                a++;
            }
            printf("%lld\n",ans);
        }
    }
    //free();   //if pointer array
    return 0;
}
