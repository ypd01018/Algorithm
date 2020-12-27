#include<bits/stdc++.h>
#define endl "\n"
#define MAX 999'999'999
#define mt make_tuple
using namespace std;
int n,m,mat[105][105];
int main()
{
    cin >> n >> m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mat[i][j]=MAX;
        }
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        mat[a][b]=min(mat[a][b],c);
    }

    for(int via=1;via<=n;via++)
    {
        for(int from = 1;from<=n;from++)
        {
            if(mat[from][via]==MAX) continue;
            for(int to=1;to<=n;to++)
            {
                if(mat[via][to]==MAX || from == to) continue;
                
                mat[from][to] = min(mat[from][to],mat[from][via]+mat[via][to]);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(mat[i][j]==MAX) cout << 0 <<' ';
            else cout << mat[i][j] << ' ';
        }
        cout << endl;
    }


}