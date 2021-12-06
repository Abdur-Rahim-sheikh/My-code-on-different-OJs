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

int main(){
    int i,j,k,n,m,val,test;
    //freopen("000input.txt","r",stdin);
    string s,t;
    cin>>test;
    while(test--){
        cin>>s>>t;
        vector<int>st[26];
        int len=s.size();
        for(i=0;i<len;i++)st[s[i]-'a'].pb(i);
        int len2=t.size();
        int pos=-1,cnt=1;
        for(i=0;i<len2;i++){
            k=t[i]-'a';
            int next=upper_bound(all(st[k]),pos)-st[k].begin();

            //p2(next,st[k].size());
            if(next<st[k].size())pos=st[k][next];
            else if(st[k].size())cnt++,pos=st[k][0];
            else break;
        }
        if(i==len2)cout<<cnt<<endl;
        else cout<<-1<<endl;
    }
    //free();   //if pointer array
    return 0;
}
