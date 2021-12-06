#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
#define Hare cout<<"hare"<<endl

/** A prize giving problem of Iqbal Aziz Khan sir.**/


using namespace std;
int grid[9][9];
pii find()
{
    int i,j,cnt,low=10,k=0;
    bool row=true;
    pii ans=mp(-1,-1);
    for (i= 0; i < 9; i++) {
        for (j = 0,cnt=0; j < 9; j++) {
            if (!grid[i][j])cnt++;
        }
        if(cnt<low and cnt>0){
            low=cnt;
            k=i;
        }
    }
    for (j= 0; j < 9; j++) {
        for (i = 0,cnt=0; i < 9; i++) {
            if (!grid[i][j])cnt++;
        }
        if(cnt<low and cnt>0){
            low=cnt;
            k=j;
            row=false;
        }
    }

    if(row){
        for(i=0;i<9;i++){
            if(!grid[k][i])break;
        }
    }

    else{
        for(i=0;i<9;i++){
            if(!grid[i][k])break;
        }
    }

    if(i<9){
        if(row)ans=mp(k,i);
        else ans=mp(i,k);
    }
    return ans;
}

bool check(int row, int col, int n)
{
    for (int j = 0; j < 9; j++) {
        if (grid[row][j] == n) {
            return false;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == n) {
            return false;
        }
    }
    int x = row / 3 * 3;
    int y = col / 3 * 3;
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (grid[i][j] == n) {
                return false;
            }
        }
    }
    return true;
}

bool sudoku()
{


    pii ans=find();
    //cout<<ans.first<<' '<<ans.second<<endl;
    if (ans.first==(-1)) {
        return true;
    }
    int row=ans.first,col=ans.second;
    for (int x = 1; x <= 9; x++) {
        if (check(row, col, x)) {
            grid[row][col] = x;
            if (sudoku()) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void print()
{
    int i,j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d",grid[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int T,cnt=0;

    //freopen("000input.txt","r",stdin);
    cin >> T;
    string s;
    while (T--) {
        for (int i = 0; i < 9; i++) {
                cin>>s;
            for (int j = 0; j < 9; j++) {
                if(s[j]=='.')grid[i][j]=0;
                else grid[i][j]=s[j]-'0';
            }
        }
        sudoku();
        printf("Case %d:\n",++cnt);
        print();
    }
    return 0;
}
