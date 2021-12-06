#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;
struct ids{
    int val,pos;
};
bool comp(ids a,ids b){return a.val<b.val;}
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,s;

    //freopen("000input.txt","r",stdin);

    cin>>test;
    while(test--){
        scanf("%d %d",&n,&s);
        ids times[n+5];
        for(i=0;i<n;i++){
            scanf("%d%*c%d%*c%d",&j,&k,&m);
            times[i].val=(j*3600+k*60+m);
            times[i].pos=i+1;
        }
        sort(times,times+n,comp);
        priority_queue<int,vector<int>,greater<int>>out;
        out.push(times[0].pos);
        val=times[0].val;
        for(i=1;i<n;i++){
            if(times[i].val>=val+s)val=times[i].val,out.push(times[i].pos);

        }
        printf("%d\n",out.size());
        while(!out.empty()){
            val =out.top();
            out.pop();
            if(!out.empty())printf("%d ",val);
        }
        printf("%d\n",val);
    }
    //free();   //if pointer array
    return 0;
}
