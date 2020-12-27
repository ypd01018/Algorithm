#include<bits/stdc++.h>
#define endl "\n"
#define MAX 200
using namespace std;
int n,m;
double k;
double mat[MAX][MAX];
void make()
{
    for(int i=0;i<MAX+1;i++)
    {
        mat[i][0]=1;
    }
    //mat[0][1]=1;

    for(int i=1;i<MAX+1;i++)
    {
        for(int j=1;j<=MAX;j++)
        {
            mat[i][j]=mat[i-1][j]+mat[i-1][j-1];
        }
    }
}
int main()
{   

    make();
    string ans="";
    cin >> n >> m >> k;
    int size = n+m;
    if(k > mat[size][n])
    {
        cout << -1;
        return 0;
    }
    else
    {
        for(int i=0;i<size;i++)
        {
            if(k>mat[n+m-1][m])
            {
                ans.append("z");
                k -= mat[n+m-1][m];
                m--;
            }
            else
            {
                ans.append("a");
                n--;
            }
            
        }
    }
    for(int i=0;i<ans.size();i++)
    cout << ans[i];

}