#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (bool)val&(1<<pos)
using namespace std;
class trie{
    int total;
    struct box{
        int cnt;
        int alpha[53];

    }arr[100005];

    void refresh(){
        arr[total].cnt=0;
        memset(arr[total].alpha,-1,sizeof(arr[total].alpha));
        total++;
        return;
    }
public:
    void init(){
        total=0;
        refresh();
        return;
    }
    int makeAndCheck(string &a,bool checking){
        int len=a.size(),k,cur=0;
        for(int i=0;i<len;i++){
            if(a[i]>='A' && a[i]<='Z')k=a[i]-'A';
            else k=a[i]-'a'+26;

            if(arr[cur].alpha[k]==(-1)){
                if(checking)return 0;
                arr[cur].alpha[k]=total;
                refresh();
            }
            cur=arr[cur].alpha[k];
        }
        if(!checking)arr[cur].cnt++;

        return arr[cur].cnt;
   }

}tree;


int main(){

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    cin>>test;
    string s,a;
    while(test--){

        tree.init();
        printf("Case %d:\n",++t);
        scanf("%d",&n);
        for(i=0;i<n;i++){
            cin>>a;
            if(a.size()>2)sort(a.begin()+1,a.end()-1);
            //cout<<a<<endl;
            tree.makeAndCheck(a,false);
        }
        scanf("%d",&m);
        cin.ignore();
        for(i=0;i<m;i++){
            getline(cin,s);
            int combination=1;;
            stringstream ss(s);
            while(ss>>s){
                if(s.size()>2)sort(s.begin()+1,s.end()-1);
                combination*=tree.makeAndCheck(s,true);
            }
            printf("%d\n",combination);
        }
    }
    //free();   //if pointer array
    return 0;
}
