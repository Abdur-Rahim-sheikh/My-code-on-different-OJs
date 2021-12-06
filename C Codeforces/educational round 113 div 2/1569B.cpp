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
    string s;
    while(test--){
        cin>>n>>s;
        int twos=0;
        for(i=0;i<n;i++)if(s[i]=='2')twos++;
        if(twos==1 or twos==2){
            printf("NO\n");
            continue;
        }
        // dbg(twos);
        vector<vector<char>> arr(n,vector<char>(n,'='));
        int prev = -1,last;
        
        for(i=0;i<n;i++){
            arr[i][i]='X';
            if(s[i]=='1')continue;
            if(prev==-1)prev=last=i;
            else{
                arr[prev][i]='+';
                arr[i][prev]='-';
                prev = i;
            }
        }
        if(twos){
            arr[prev][last]='+';
            arr[last][prev]='-';
        }
        
        printf("YES\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)printf("%c",arr[i][j]);
            printf("\n");
        }
    }
    //free();   //if pointer array
    return 0;
}