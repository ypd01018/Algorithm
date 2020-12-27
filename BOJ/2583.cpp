#include<bits/stdc++.h>
#define val first
#define check second
using namespace std;
int M,N,K,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
pair<bool,bool> mat[102][102];
queue<pair<int,int>> q;
vector<int> v;
int main()
{
    cin >> M >> N >> K;
    for(int k=0;k<K;k++)
    {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=y1;i<y2;i++)
        {
            for(int j=x1;j<x2;j++)
            {
                mat[i][j].first=1;
            }
        }
    }

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            int cnt=0;
            if(!mat[i][j].val && !mat[i][j].check)
            {
                mat[i][j].check=1;
                q.push({i,j});
                while(!q.empty())
                {
                    cnt++;
                    int y,x; tie(y,x) = q.front(); q.pop();
                    for(int n = 0 ; n < 4 ; n++)
                    {
                        int ny=y+dy[n],nx=x+dx[n];
                        if(ny >= 0 && nx >= 0 && ny <M && nx < N && !mat[ny][nx].val && !mat[ny][nx].check)
                        {
                            mat[ny][nx].check=1;
                            q.push({ny,nx});
                        }
                    }
                }
            }
            if(cnt) v.push_back(cnt);
        }
    }

    cout << v.size() << endl;
    sort(v.begin(), v.end());
    for(int i:v)
    {
        cout << i << " ";

    }
}