#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;

int main()
{

    int i,j,k,m,n,val,cnt,test;

    //freopen("000input.txt","r",stdin);

    cin>>m>>n;
    int arr[m+5]={0},prev=0,save;
    int  center[n+100]={0};
    for(i=0;i<n;i++){
        scanf("%d",&val);
        arr[val]++;
        if(center[arr[val]-1]>0)center[arr[val]-1]--;
        center[arr[val]]++;

    }
    for(i=1;i<=n;i++){
       // cout<<i<<"is "<<center[i]<<"time"<<endl;
        if(center[i]>prev){
            prev=center[i];
            save =i;
        }
    }
    int num[100],ammount[100],most;
    for(i=1,cnt=0;i<=m;i++){
        if(arr[i]!=0 && arr[i]!=save){
            num[cnt]=i;
            ammount[cnt]=arr[i];
            cnt++;
            if(cnt>2 || abs(arr[i]-save)>2)break;
        }
        else if(arr[i]==save)most = i;
    }
    //cout<<prev<<' '<<save<<endl;
    if(i<=m)printf("*\n");
    else if(cnt ==2 && abs(ammount[0]-ammount[1]==1)){
            cout<<num[0]<<' '<<num[1]<<endl;
        val = ammount[0]<ammount[1]?num[0]:num[1];
        printf("-%d +%d\n",most,val);
    }
    else if(cnt==1 && ammount[0]-prev==1){
        printf("-%d\n",num[0]);
    }

    else if(cnt==1 && prev-ammount[0]==1){
        printf("+%d\n",num[0]);
    }
    else printf("*\n");
    //free();   //if pointer array
    return 0;
}
