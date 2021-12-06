#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>

using namespace std;

int main()
{

    ll i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);

    cin>>test;
    string a;
    cin.ignore();
    while(test--){
        getline(cin,a);
        ll len=a.size();
        queue<string>first;
        stack<string>opa;
        stack<ll>last;
        for(i=0;i<len;i++){

            if((a[i]>='0' && a[i]<='9') || (a[i]=='-' && a[i+1]>='0' && a[i+1]<='9')){
                string tem;
                if(a[i]=='-')tem+=a[i],i++;
                while(a[i]>='0' && a[i]<='9'){
                    tem+=a[i];
                    i++;
                }

                first.push(tem);

            }
            else{


                   if(a[i]=='/' || a[i]=='*' || a[i]=='%'){

                    if(!opa.empty())while(opa.top()=="*" || opa.top()=="/" || opa.top()=="%"){
                        first.push(opa.top());
                        opa.pop();
                        if(opa.empty())break;
                    }

                }
               /* else if(a[i]=='*'){

                    if(!opa.empty())while(opa.top()=="*" || opa.top()=="%"){
                        first.push(opa.top());
                        opa.pop();
                        if(opa.empty())break;
                    }

                }*/

                else{

                    while(!opa.empty())first.push(opa.top()),opa.pop();
                }
                string tem;
                tem+=a[i];
                opa.push(tem);
                i++;
            }
        }

        while(!opa.empty())first.push(opa.top()),opa.pop();
        while(!first.empty()){
            string tem =first.front();
            first.pop();
            if((tem[0]>='0' && tem[0]<='9') || (tem[0]=='-' && tem.size()>1) ){
                ll temll=0,len=tem.size();
                bool neg=false;
                ll i=0;
                if(tem[i]=='-')neg=true,i++;
                for( ;i<len;i++){
                    temll=temll*10+tem[i]-'0';
                }
                if(neg)temll = -temll;

                last.push(temll);

            }
            else{
                ll b=last.top();last.pop();
                ll a=last.top();last.pop();
                ll c;
                if(tem=="+")c=a+b;
                else if(tem=="-")c=a-b;
                else if(tem=="*")c=a*b;
                else if(tem=="/")c=a/b;
                else if(tem=="%")c=a%b;
                last.push(c);

            }
        }
        printf("%lld\n",last.top());

    }
    //free();   //if poller array
    return 0;
}

