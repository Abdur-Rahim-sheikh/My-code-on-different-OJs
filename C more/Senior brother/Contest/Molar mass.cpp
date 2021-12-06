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

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        string a;
        cin>>a;
        int chon[10]={0};
        int len = a.size();
        for(i=0;i<len;i++){

            if(a[i]=='C'){
                if((a[i+1]>='C' && a[i+1]<='O') || (i+1)==len )chon[0]++;
                else{
                    i++;
                    int sum=0;
                   while(a[i]>='1' && a[i]<='9') sum= sum*10+a[i]-'0',i++;
                   chon[0]+=sum;
                   i--;
                }
            }
            else if(a[i]=='H'){
                if((a[i+1]>='C' && a[i+1]<='O') || (i+1)==len)chon[1]++;
                else{
                    i++;
                    int sum=0;
                   while(a[i]>='1' && a[i]<='9') sum= sum*10+a[i]-'0',i++;
                   chon[1]+=sum;
                   i--;
                }
            }

            else if(a[i]=='O'){
                if((a[i+1]>='C' && a[i+1]<='O') || (i+1)==len)chon[2]++;
                else{
                    i++;
                    int sum=0;
                   while(a[i]>='1' && a[i]<='9') sum= sum*10+a[i]-'0',i++;
                   chon[2]+=sum;
                   i--;
                }
            }
            else if(a[i]=='N'){
                if((a[i+1]>='C' && a[i+1]<='O') || (i+1)==len)chon[3]++;
                else{
                    i++;
                    int sum=0;
                   while(a[i]>='1' && a[i]<='9') sum= sum*10+a[i]-'0',i++;
                   chon[3]+=sum;
                   i--;
                }
            }
             //cout<<chon[0]<<' '<<chon[1]<<' '<<endl;
        }
        double ans = double((chon[0]*12.01)+(chon[1]*1.008)+(chon[2]*16.00)+(chon[3]*14.01));
        //cout<<ans<<endl;
        printf("%0.3lf\n",ans);
    }
    //free();   //if pointer array
    return 0;
}
