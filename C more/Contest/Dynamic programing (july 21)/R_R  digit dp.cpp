#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli dp[10][2][100][100];
lli val;
lli ch(string s)
 {
   lli num=0,sum=0;
   for(int i=0;i<s.length();i++)
   {
    num=num*10+s[i]-'0';
    sum+=s[i]-'0';
   }
   if(num%val==0 && sum%val==0) return 1;
   else return 0;
 }

lli  solve(lli idx,bool tight,lli num,  string s,lli n ,lli sum)
 {
    if(idx>=n){
        if(num %val==0 && sum%val==0) return 1;
        else return 0;
    }
  
    if(dp[idx][tight][num][sum]!=-1){
        return dp[idx][tight][num][sum];
    }
   if(tight==1){
    lli  ret=0;
    for(int i=0;i<=s[idx]-'0';i++){
        lli  numm=num*10+i;
        lli  summ=sum+i;
        if(i==s[idx]-'0') ret+=solve(idx+1,1,numm%val,s,n,summ);
        else ret+=solve(idx+1,0,numm%val,s,n,summ);      
    }
    dp[idx][tight][num][sum]=ret;
    // cout<<" index "<<idx<<" tight "<<tight<<" ans "<<ret<<endl;
    return ret;
   }
   else{
     lli ret=0;
      for(int i=0;i<=9;i++) {
        lli numm=num*10+i;
        lli summ=sum+i;
        ret+=solve(idx+1,0,numm%val,s,n,summ);
    }
    dp[idx][tight][num][sum]=ret;
   //  cout<<" index "<<idx<<" tight "<<tight<<" ans "<<ret<<endl;
    return ret;
   }
 }

int main()
{
 lli t;
   cin>>t;
   lli cas=1;
   while(t--)
    {
     
      string l,r;
     
       cin>>l>>r>>val;
       if(val>=100)
        {
            cout<<"Case "<<cas++<<": ";
            cout<<0<<endl;
            continue;
        }
        memset(dp,-1,sizeof dp);
        lli ans1=solve(0,1,0,r,r.length(),0);
        memset(dp,-1,sizeof dp);
        lli ans2=solve(0,1,0,l,l.length(),0);
        if(ch(l)) ans1++;
        cout<<"Case "<<cas++<<": ";
        cout<<ans1-ans2<<endl;
    }
}