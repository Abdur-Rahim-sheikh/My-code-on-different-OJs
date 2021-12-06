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

    cin>>test;

    while(test--){
        scanf("%d",&n);
        //fill(prop,prop+(4*n),0);
        int arr[n+5],mini[n+5];
        for(i=1;i<=n;i++) scanf("%d",&arr[i]);
        arr[0]=arr[n+1]=-1;
        ///next min
        stack<int>st;
        st.push(1);
        for(i=2;i<=n+1;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                mini[st.top()]=i-st.top();
                //cout<<arr[st.top()]<<' '<<i-st.top()<<endl;
                st.pop();
            }
            st.push(i);
        }
        st.pop();

        ///prev min
        st.push(n);

        for(i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<arr[st.top()]){
                mini[st.top()]+=st.top()-i-1;
                st.pop();
            }
            st.push(i);
        }
        ll ans=0;
         for(i=1;i<=n;i++){
            //cout<<arr[i]<<' '<<mini[i]<<endl;
            ans = max(ans,(ll)arr[i]*mini[i]);
         }
        printf("Case %d: %lld\n",++t,ans);
    }



    //free();   //if pointer array
    return 0;
}
