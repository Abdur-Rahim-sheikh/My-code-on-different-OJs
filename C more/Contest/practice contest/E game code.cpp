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

    int i,j,k,m,n,val,t=0,cnt,total;
    //freopen("000input.txt","r",stdin);

    cin>>m>>n>>k;
    int arr[n+5];
    for(i=0;i<=n;i++) scanf("%d",&arr[i]);
    val=arr[n];
    for(i=0,total=0;i<n;i++){
        int cp =val;
        cnt=0;
        while(cp>0 || arr[i]>0){
            if((cp&1) != (arr[i]&1))cnt++;
            cp=cp>>1;
            arr[i]=arr[i]>>1;
            if(cnt>k)break;
        }
        if(cnt<=k)total++;
    }
    printf("%d\n",total);
    //free();   //if pointer array
    return 0;
}
