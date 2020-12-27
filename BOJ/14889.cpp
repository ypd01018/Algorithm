#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,mat[25][25],mn=INT_MAX;
bool visited[22];

void DFS(int a,int cnt)
{
    if(cnt == n/2)
    {
        //cout <<"this";
        vector<int> t1,t2;
        for(int i=0;i<n;i++)
        {
            if(visited[i]) t1.push_back(i);
            else t2.push_back(i);
        }
        int tot1=0,tot2=0;
        //cout << "t1.size():"<<t1.size()<<"  t2.size():"<<t2.size()<<endl;
        for(int i=0;i<t1.size();i++)
        {
            for(int j=i+1;j<t1.size();j++)
            {
                tot1 += mat[t1[i]][t1[j]]+mat[t1[j]][t1[i]];
                tot2 += mat[t2[i]][t2[j]]+mat[t2[j]][t2[i]];
            }
        }

        int diff = abs(tot1 - tot2);
        //cout << "diff:" << diff << endl;
        mn = min(diff,mn);
        return;
    }

    for(int i=a+1;i<n;i++)
    {
        if(visited[i]) continue;
        visited[i]=1;
        DFS(i,cnt+1);
        visited[i]=0;
    }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        visited[i]=1;
        DFS(i,1);
        visited[i]=0;
    }

    cout << mn;
}