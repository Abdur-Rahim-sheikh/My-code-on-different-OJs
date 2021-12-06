#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))

//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;

int main(){
    int i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    cin>>m;
    map<string,int> mp;
    string a,b,arr[2*m+5];
    vector<int>vec[2*m+5];
    for(i=0,cnt=0;i<m;i++){
        cin>>a>>b;
        if(!mp[a])mp[a]=++cnt,arr[cnt]=a;
        if(!mp[b])mp[b]=++cnt,arr[cnt]=b;
        vec[mp[a]].pb(mp[b]);
        vec[mp[b]].pb(mp[a]);
    }
    n=cnt;
    printf("%d\n",n);

    for(i=1;i<=n;i++){
        sort(vec[i].begin(),vec[i].end());
        int pre=0;
        for(j=1,cnt=0;j<=n;j++){
            if(i!=j and binary_search(vec[i].begin(),vec[i].end(),j)==false){
                int tem=0;
                for(k=0;k<vec[j].size();k++){
                    if(binary_search(vec[i].begin(),vec[i].end(),vec[j][k]))
                        tem++;
                }
                if(tem>pre)pre=tem,cnt=1;
                else if(tem==pre)cnt++;
            }
        }
        cout<<arr[i]<<' '<<cnt<<endl;
    }
    //free();   //if pointer array
    return 0;
}
