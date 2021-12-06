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

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        vi arr(n);
        int satisfied=0;
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            arr[i]--;
        }

        vector<bool> has(n,false);
        vi ans(n,-1);
        for(i=n-1;i>=0;i--){
            if(has[arr[i]]==false){
                ans[i]=arr[i];
                has[arr[i]]=true;
                satisfied++;
            }
        }
        
        int cnt=0;
        int bug = -1;
        for(i=n-1;i>=0;i--){
            while(has[cnt])cnt++;
            if(ans[i]==-1){
                ans[i]=cnt;
                has[cnt]=true;
                if(i==cnt)bug = cnt;
            }
            
        }
        //dbg(bug);
        //dbg(has,ans);
        if(bug!=-1){
            i=0;
            while(ans[i]!=arr[bug])i++;
            ans[bug]=arr[bug];
            ans[i]=bug;
        }
        printf("%d\n",satisfied);
        for(i=0;i<n;i++){
            printf("%d ",ans[i]+1);
        }
        printf("\n");
    }
    //free();   //if pointer array
    return 0;
}
