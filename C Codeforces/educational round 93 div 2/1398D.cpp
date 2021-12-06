#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
    cin>>n>>m>>k;
    priority_queue<int>a,b,c;
    for(i=0;i<n;i++){
        scanf("%d",&val);
        a.push(val);
    }
    a.push(0);
    for(i=0;i<m;i++){
        scanf("%d",&val);
        b.push(val);
    }
    b.push(0);
    for(i=0;i<k;i++){
        scanf("%d",&val);
        c.push(val);
    }
    c.push(0);
    int ans=0;
    while(true){
        int x=a.top()*b.top(),y=a.top()*c.top();
        int z=b.top()*c.top();
        if(x>=y and x>=z){
            a.pop();
            b.pop();
            ans+=x;
        }
        else if(y>=x and y>=z){
            a.pop();
            c.pop();
            ans+=y;
        }
        else {
            b.pop();
            c.pop();
            ans+=z;
        }
        if((x+y+z)==0)break;

    }
    cout<<ans<<endl;
    //free();   //if pointer array
    return 0;
}
