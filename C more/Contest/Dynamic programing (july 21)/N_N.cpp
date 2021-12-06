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
    ///minimum insertion to make palindrome
    cin>>test;
    string s;
    while(test--){
        cin>>s;
        
        n = s.size();
        vector<vector<bool>> palin(n,vector<bool>(n,0));
        int p;
       
        for(i=0;i<n;i++){  
            for(j=0;j+i<n;j++){
                palin[j][j+i]=(s[j]==s[j+i]) and (i>1?palin[j+1][j+i-1]:true);  
            }
        }
        // dbg(palin);
        vi partition(n);
        for(i=0;i<n;i++){
            if(palin[0][i]==1){
                partition[i]=0;
                continue;
            }
            partition[i]=n;
            for(j=0;j<i;j++){
                if(palin[j+1][i]==1 and partition[j]+1<partition[i])partition[i]=partition[j]+1;
            }
        }
        printf("Case %d: %d\n",++t,partition[n-1]+1);

    }

    //free();   //if pointer array
    return 0;
}
