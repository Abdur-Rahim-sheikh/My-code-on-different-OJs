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

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        scanf("%d",&n);
        priority_queue<int,vector<int>,greater<int> > q;
        pii arr[n+2];
        for(i=0;i<n;i++)scanf("%d %d",&arr[i].first,&arr[i].second);
        sort(arr,arr+n);
        int best=1;
        q.push(arr[0].second);
        for(i=1;i<n;i++){
            //cout<<q.top()<<' '<<arr[i].second<<endl;
            if(q.top()<arr[i].first)q.pop();
            q.push(arr[i].second);

            if(q.size()>best)best=q.size();
        }
        printf("Case %d: %d\n",++t,best);
    }
    //free();   //if pointer array
    return 0;
}
