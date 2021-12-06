#include<bits/stdc++.h>

#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define p1(n) printf("showing %d\n",n)
#define p2(m,n) printf("showing %d %d\n",m,n)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define x first
#define y second
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    string s;
    vector<int>cnt;
    while(test--){
        cin>>n>>s;
        vector<int>arr;
        int cnt=1;
       
        for(i=1;i<n;i++){
            if(s[i]==s[i-1])cnt++;
            else arr.pb(cnt),cnt=1;
        }
        if(!arr.size() or s[0]!=s[n-1])arr.pb(cnt);
        else arr[0]+=cnt;
        
        int ans=0;
        for(i=0;i<arr.size();i++){
            ans+=arr[i]/3;
        }
        if(arr.size()==1){
            ans+=(arr[0]>3 and arr[0]%3>0)?1:0;
        }
        
        printf("%d\n",ans);
    }

    //free();   //if pointer array
    return 0;
}
