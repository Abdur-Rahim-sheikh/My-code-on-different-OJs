#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int r;
        scanf("%d",&r);
        vector<pair<char,char> >v;
        int repl[300];
        for(char i='A';i<='Z';++i)
        {
            repl[i]=i;
        }
        repl['_']='_';
        for(int i=1;i<=r;++i)
        {
            char node1,node2;
            scanf(" %c %c",&node1,&node2);
            v.push_back({node1,node2});
        }
        for(char i='A';i<='Z';++i)
        {
            char src=i;
            for(int j=0;j<r;++j)
            {
                if(v[j].second==src)
                {
                    src=v[j].first;
                }
            }
            repl[i]=src;
        }
        for(int i=0;s[i];++i)
        {
            s[i]=repl[s[i]];
        }
        printf("%s\n",s);
    }
    return 0;
}
