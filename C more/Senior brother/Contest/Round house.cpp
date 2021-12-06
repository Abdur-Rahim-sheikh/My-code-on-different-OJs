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

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    cin>>n>>m>>val;
    if(val>=0){
        int ans;
        ans = (m+val)%n==0? n: (m+val)%n;
        cout<<ans<<endl;
    }
    else{
        i= abs(val);
        while(i--){
            m--;
            if(m==0)m=n;
        }
        cout<<m<<endl;

    }
    //free();   //if pointer array
    return 0;
}
