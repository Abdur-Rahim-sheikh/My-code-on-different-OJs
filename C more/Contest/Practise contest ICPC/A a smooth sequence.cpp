#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (bool)val&(1<<pos)
using namespace std;

int main(){

    ll i,j,k,m,n,val,t=0,cnt,test,d;

    //freopen("000input.txt","r",stdin);
    while(cin>>n && n!=0){
        ll arr[n+5];
        scanf("%lld %lld",&d,&arr[0]);
        queue<ll> st;
        for(i=1;i<n;i++){
            scanf("%lld",&arr[i]);
            if(abs(arr[i]-arr[i-1])>d)st.push(i);
        }
        if(st.size()>2)printf("N\n");
        else if(st.empty() || (st.size()==1 &&(st.front()==1 || st.front()==n-1)))
                printf("Y\n");
        else{
            if(st.size()==1){
                ll sum=abs(arr[st.front()-1]-arr[st.front()+1]);
                if(d*2>=sum)printf("Y\n");
                else printf("N\n");
            }
            else{
                k=st.front();
                st.pop();
                j=st.front();
                ll sum=abs(arr[k+1]-arr[k-1]);
                if(j!=(k+1) || (d*2<sum))printf("N\n");
                else printf("Y\n");
            }
        }
    }
    //free();   //if pointer array
    return 0;
}
