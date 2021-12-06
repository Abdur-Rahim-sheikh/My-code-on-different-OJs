#include<bits/stdc++.h>
using namespace std;


int main()
{
    int i,j,k,m,n,len,sign=0,test,start1=0,start2;
    char str[1000005];

    scanf("%d ",&test);
    while(test--){
        cin>>str;
        len=strlen(str);

    if(len%2==0)
    {
        m=i=len/2-1;
        n=j=len/2;
    }
    else
        m=n=i=j=len/2;
    for(;j<len;i--,j++)
    {

        if(sign==0 && str[i]!=str[j])
        {


            sign=1;
            if(str[i]>str[j])             ///if middle left is greater then middle right
            {
                str[j]=str[i];

            }
            else{
                str[i]++;
                str[j]=str[i];

                start1=i+1;
                start2=j-1;
            }
        }
        else if(str[i]!=str[j])
            str[j]=str[i];


    }
    if(sign==0)
    {
        i=m;
        j=n;
        ///sign 0 means the string is palindrome
        //printf("%d %d",i,j);
        while(str[i]=='9')i--,j++;
        if(i<0){

            len+=1;
            str[0]='1';
            memset(str+1,'0',len-2);
            str[len-1]='1';
            str[len]='\0';

        }
        else{
            str[i]++;
            str[j]=str[i];
            for(i=i+1;i<j;i++)str[i]='0';
        }

    }
    else if(start1<=start2 && start1!=0)
    {
        for(i=start1;i<=start2;i++)
            str[i]='0';
    }
    printf("%s\n",str);
}



    return 0;
}
