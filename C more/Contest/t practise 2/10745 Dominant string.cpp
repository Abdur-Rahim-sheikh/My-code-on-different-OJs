#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;
bool comp(string a,string b){return a.size()>b.size();}
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);

    string a[20000];
    map<string,int>ppp;
    while(cin>>a[t++]);
    bool checked[t+5]={false};
    sort(a,a+t,comp);
    for(i=0;i<t;i++){
        if(checked[i]==true)continue;
        int arr[30]={0};
        int len= a[i].size();

        for(k=0;k<len;k++) arr[a[i][k]-'a']++;

        for(j=i+1;j<t;j++){
            len = a[j].size();
            int tem[30]={0};
            for(k=0;k<len;k++){
                 tem[a[j][k]-'a']++;
                 if(arr[a[j][k]-'a']<tem[a[j][k]-'a'])break;
            }
            if(k==len){
                ppp[a[i]]=i;
                checked[j]=true;
            }
        }
    }
    for(auto u: ppp)cout<<u.first<<endl;
    //free();   //if pointer array
    return 0;
}
