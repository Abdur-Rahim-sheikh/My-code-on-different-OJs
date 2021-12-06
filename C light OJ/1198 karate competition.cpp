#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;
vector<int> arr,arr2,left;
int exactBigger(int val){
    int hi=arr.size()-1,lo=0,mid;
    while(hi>=lo){
        mid=(hi+lo)/2;
        if(arr[mid]>val && (arr[mid+1]<=val || mid==arr.size()-1))break;
        else if(arr[mid]>val)lo=mid+1;       ///Cause arrays are sorted in decreasing order
        else hi=mid-1;
    }
    if(hi<lo)return -1;
    else return mid;
}

int equals(int val){
    int hi=arr2.size()-1,lo=0,mid;
    while(hi>=lo){
        mid=(hi+lo)/2;
        if(arr2[mid]==val)break;
        else if(arr2[mid]>val)lo=mid+1;       ///Cause arrays are sorted in decreasing order
        else hi=mid-1;
    }
    if(hi<lo)return -1;
    else return mid;
}
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);

    cin>>test;

    while(test--){
        scanf("%d",&n);

        for(i=0;i<n;i++)scanf("%d",&val),arr.pb(val);
        for(i=0;i<n;i++)scanf("%d",&val),arr2.pb(val);
        sort(arr.begin(),arr.end(),greater<int>());
        sort(arr2.begin(),arr2.end(),greater<int>());
        for(i=0,cnt=0;i<n;){
            int pos=exactBigger(arr2[i]);
            //cout<<arr[i]<<'*'<<pos<<endl;
            if(pos>=0){
                cnt+=2;
                arr.erase(arr.begin()+pos);
                arr2.erase(arr2.begin()+i);
                n--;
            }
            else i++;

        }
        for(i=0;i<n;){
            int pos=equals(arr[i]);
            //cout<<arr[i]<<'#'<<pos<<endl;
            if(pos>=0){
                cnt++;
                arr.erase(arr.begin()+i);
                arr2.erase(arr2.begin()+pos);
                n--;
            }
            else i++;
        }
        printf("Case %d: %d\n",++t,cnt);
        arr.erase(arr.begin(),arr.end());
        arr2.erase(arr2.begin(),arr2.end());
    }



    //free();   //if pointer array
    return 0;
}
