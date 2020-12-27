#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int N,x,y,d,z,cnt;
bool mat[105][105];

void dragon()
{
    vector<pair<int,int>> v;
    v.push_back({y,x});
    
    if(d==0) v.push_back({y,x+1});
    else if(d==1) v.push_back({y-1,x});
    else if(d==2) v.push_back({y,x-1});
    else v.push_back({y+1,x});
    
    for(int i=1;i<=z;i++)
    {
        pair<int,int> core = v.back();
        int start=v.size()-2;
        for(int i=start;i>=0;i--)
        {
            int y_v = v[i].first, x_v = v[i].second;
            int push_y = core.first-(core.second-x_v),
            push_x = core.second+(core.first-y_v);
            v.push_back({push_y,push_x});
        }
    }
    for(int i=0;i<v.size();i++)
    {
        mat[v[i].first][v[i].second]=1;
    }
}

int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> x >> y >> d >> z;
        dragon();
    }
    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=100;j++)
        {
            if(mat[i][j] && mat[i][j+1] && mat[i+1][j] && mat[i+1][j+1])
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}