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
bool vowel(char ch){
    return ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U';
}

bool turn_to_good(string s){
    vvi dp(2,vi(s.size()+1,0));

    //dp[0] for vowel <<==>>  dp[1] for consonant
    for(int i=1;i<=s.size();i++){
        if(s[i-1]=='?'){
            dp[0][i] = dp[0][i-1]+1;
            dp[1][i] = dp[1][i-1]+1;
            
        }
        else if(vowel(s[i-1])){
            dp[1][i] = 0;
            dp[0][i] = dp[0][i-1]+1;
        }
        else {
            dp[0][i] = 0;
            dp[1][i] = dp[1][i-1]+1;
        }
        if(dp[0][i]>=3 and dp[1][i]>=5)return false;
        d
    }
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    string s;
    while(test--){
        printf("Case %d: ",++t);
        cin>>s;
        // check if already bad
        bool bad=false;
        int vowel=0,consonant=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='?') continue;
            if(vowel(s[i])) vowel++,consonant=0;
            else consonant++,vowel=0;
            if(vowel==3 or consonant==5) break;
        }
        if(i<s.size()){
            printf("BAD\n");
            continue;
        }

        //If it can be turned to good and bad
    }
    //free();   //if pointer array
    return 0;
}
