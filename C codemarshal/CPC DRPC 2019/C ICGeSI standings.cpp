#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483648
#define ll long long
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
//#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
struct pack{
    int id,s,tp;
    vi vec;
};

bool check(int prevs,int prevp,int curs,int curp){
    if(prevs<curs)return true;
    else if(prevs==curs and prevp>=curp) return true;
    else return false;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        vector<pack> arr(n+1);
        int id,s,tp,m;
        for(i=0;i<n;i++){
            cin>>id>>s>>tp>>m;
            arr[id].vec.resize(m);
            arr[id].s=s;
            arr[id].tp=tp;
            for(j=0;j<m;j++)cin>>arr[id].vec[j];
        }
        vi leak(n);
        for(int &u:leak)cin>>u;
        int prevs=arr[leak[n-1]].s,prevp=arr[leak[n-1]].tp;
        for(i=n-2;i>=0;i--){
            k = leak[i];
            if(check(prevs,prevp,arr[k].s,arr[k].tp)){
                prevs=arr[k].s;
                prevp=arr[k].tp;
            }
            else{
                int tems=arr[k].s,temp=arr[k].tp;
                for(j=0;j<arr[k].vec.size();j++){
                    tems++;
                    temp+=arr[k].vec[j];
                    if(check(prevs,prevp,tems,temp)){
                        prevs=tems;
                        prevp=temp;
                        break;
                    }
                }
                if(j==arr[k].vec.size())break;
            }
        }
        if(i<0)printf("Case %d: We respect our judges :)\n",++t);
        else printf("Case %d: Say no to rumour >:\n",++t);
    }
    //free();   //if pointer array
    return 0;
}
