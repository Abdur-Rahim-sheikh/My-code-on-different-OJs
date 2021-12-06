#include<bits/stdc++.h>

using namespace std;
int main(){
    int i,j,k,n,t=0;
    string a;
    while(cin>>a){
        if(a=="end")break;

        vector<int> seaport;
        for(i=0;i<a.size();i++){
            k=a[i]-'A';
            int pos=-1,mini=1000;
            for(j=0;j<seaport.size();j++){
                if(seaport[j]>= k && seaport[j]-k<mini){
                    mini=k-seaport[j];
                    pos=j;
                }
            }
            //cout<<pos<<' '<<k<<endl;
            if(pos>=0)seaport[pos]=k;
            else seaport.push_back(k);
        }
        printf("Case %d: %d\n",++t,seaport.size());
    }

}
