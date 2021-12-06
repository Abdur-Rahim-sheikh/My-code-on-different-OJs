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
        string s,ans;
        cin>>s;
        vi alpha(26,0);

        int len=s.size();
        for(i=0;i<len;i++)alpha[s[i]-'a']++;
        
        int single=-1;
        for(i=0;i<26;i++)if(alpha[i]==1){single=i;break;}
        if(single!=-1){
            ans+=single+'a';
            alpha[i]--;
            for(i=0;i<26;i++){
                while(alpha[i])ans+=i+'a',alpha[i]--;
            }
            cout<<ans<<endl;
            continue;
        }
        i=0;
        while(alpha[i]==0)i++;
        char ch='a'+i;
        ans+=ch;
        k = alpha[i]-1;
        i+=1;
        
        while(ans.size()<len){
            while(i<26 and alpha[i]==0)i++;
            if(i==26)break;
            alpha[i]--;
            if(k){
                ans+=ch;
                ans+='a'+i;
                k--;
            }
            else ans+='a'+i;
        }
        if(k==2){
            ans=ch+ans;
            k--;
        }
        while(k){
            ans+=ch;
            k--;
        }
        cout<<ans<<endl;
    }
    //free();   //if pointer array
    return 0;
}
