#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int N,mat[27][27],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool check[27][27];
queue<pair<int,int>> q;
vector<int> v;
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        string input;
        cin >> input;
        for(int j=0;j<N;j++)
        {
            mat[i][j]=input[j]-48;
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(mat[i][j] && !check[i][j]) 
            {
                q.push({i,j});
                check[i][j]=1;
            }
            int cnt=0;
            while(!q.empty())
            {
                cnt++;
                int y,x; tie(y,x) = q.front(); q.pop();
                for(int n=0;n<4;n++)
                {
                    int ny = y+dy[n],nx = x+dx[n];
                    if(nx >=0 && ny >= 0 && nx < N && ny < N && mat[ny][nx]==1 && !check[ny][nx])
                    {
                        check[ny][nx]=1;
                        q.push({ny,nx});
                    }
                }
            }
            if(cnt>0) v.push_back(cnt);
        }
    }

    sort(v.begin(),v.end());
    cout << v.size()<<endl;
    for(int i : v)
        cout << i << endl;
/*
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << check[i][j];
        }
        cout << endl;
    }
*/
}