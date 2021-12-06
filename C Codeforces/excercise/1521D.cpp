#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483648
#define mod 1000000007
#define ll long long
#define endl '\n'
#define PI (2*acos(0.0))
using namespace std;
char gap = 32;
template<typename T> 
ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << '{'; 
    for (const auto &x : v) os << gap << x;
        return os << '}'; 
}
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) {
        return os << '(' << p.first <<gap<<','<< gap << p.second << ')';
}
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { 
    cerr << ' ' << H;
     dbg_out(T...); 
}
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')'<<':', dbg_out(__VA_ARGS__)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define on(val,pos) (val|(1<<pos))
#define off(val,pos) (val&(~(1<<pos)))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//replace less<int> to less_equal<int> to take duplicate values
vvi net;
int sum;
vvi ans;
int bamboo_head;
int dfs(int n,int pa){
    int cnt=0,bottom=n;
    
    for(int u: net[n])if(u^pa){
        int cur_bottom = dfs(u,n);

        if(cur_bottom==-1)continue;//this child is already cut out

        cnt++;
        if(cnt==1)bottom = cur_bottom;
        else if(cnt==2){
            ans.pb({pa,n,bottom,bamboo_head});
            bottom = -1;
            bamboo_head=cur_bottom;
        }
        else ans.pb({n,u,u,bamboo_head}),bamboo_head=cur_bottom;
    }
    return bottom;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;

    while(test--){
        cin>>n;
        net.clear();
        ans.clear();
        net.resize(n+1);
        for(i=1;i<n;i++){
            scanf("%d %d",&j,&k);
            net[j].pb(k);
            net[k].pb(j);
        }

        ///idea is make group of 4 a,b,c,d
        ///a,b which is a edge we will cut
        /// current bamboo head = x so we add c,x and
        ///and now x=d current bamboo head.....

        for(i=1;i<n;i++)if(net[i].size()==1)break;
        bamboo_head=i;
        dfs(i,-1);
        cout<<ans.size()<<endl;
        for(auto x: ans){
            for(int u: x){
                printf("%d ",u);
            }
            printf("\n");
        }
    }
    //free();   //if pointer array
    return 0;
}
