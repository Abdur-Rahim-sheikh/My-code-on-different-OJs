#include<bits/stdc++.h>
#include<cstdio>
#define pb push_back
#define pii pair<int,int>

using namespace std;
bool comp(string &a,string &b){
    int i=0,j,k;
   // cout<<a<<' '<<b<<endl;
    while(a[i]==b[i])i++;
    if((a[i]|32) == (b[i]|32))return a[i]<b[i];
    j =(a[i]|32)-'a';
    k = (b[i]|32) - 'a';
    return j<k;
}
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,q;

    string a;
    cin>>test;
    while(test--){
        int ia,ib,ic,id;
        vector<string> abcd[5];
        ia=ib=ic=id=0;
        scanf("%d",&n);
        while(n--){
            cin>>a;
            if(a[0]=='A')abcd[0].pb(a);
            else if(a[0]=='B')abcd[1].pb(a);
            else if(a[0]=='C')abcd[2].pb(a);
            else abcd[3].pb(a);
        }
        sort(abcd[0].begin(),abcd[0].end(),comp);
        sort(abcd[1].begin(),abcd[1].end(),comp);
        sort(abcd[2].begin(),abcd[2].end(),comp);
        sort(abcd[3].begin(),abcd[3].end(),comp);

        scanf("%d",&q);
        j=abcd[0].size();
        k=abcd[1].size();
        m=abcd[2].size();
        n=abcd[3].size();
        cin.ignore();
        char aa[60];
        while(q--){
            //getline(cin,a);
            gets(aa);
            if(aa[0]=='A' && ia<j){
               //cout<<abcd[0][ia]<<'\n';
               printf("%s\n",abcd[0][ia].c_str());
               ia++;
            }
            else if(aa[0]=='B' && ib<k){
               // cout<<abcd[1][ib]<<'\n';
                printf("%s\n",abcd[1][ib].c_str());
                ib++;
            }
            else if(aa[0] =='C' && ic<m){
               // cout<<abcd[2][ic]<<'\n';
                printf("%s\n",abcd[2][ic].c_str());
                ic++;
            }
            else if(aa[0]=='D' && id<n){
                //cout<<abcd[3][id]<<'\n';
                printf("%s\n",abcd[3][id].c_str());
                id++;
            }
            else printf("Already Mastered\n");
        }
    }

    //free();   //if pointer array
    return 0;
}
