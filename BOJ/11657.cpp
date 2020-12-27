#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,a,b,c,arr[505], check[502][502];
vector<tuple<int,int,int>> edge;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=2;i<=n;i++)
    {
        arr[i]=999'999'999;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            check[i][j]=INT_MAX;
        }
    }
    for(int i=0;i<m;i++)
    {
        cin >> a >> b >> c;
        check[a][b] = 
        edge.push_back({a,b,c});
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<edge.size();j++)
        {
            int here = get<0>(edge[j]);
            int there = get<1>(edge[j]);
            int w = get<2>(edge[j]);

            if(arr[here]==999'999'999) continue;

            arr[there] = min(arr[there],arr[here]+w);
        }
    }

    int check[505];
    for(int i=1;i<=n;i++) check[i]=arr[i];
    {
        for(int j=0;j<edge.size();j++)
        {
            int here = get<0>(edge[j]);
            int there = get<1>(edge[j]);
            int w = get<2>(edge[j]);

            if(arr[here]==999'999'999) continue;

            arr[there] = min(arr[there],arr[here]+w);
        }
    }

    bool flag =true;

    for(int i=2;i<=n;i++)
    {

        if(check[i]!=arr[i]) 
        {flag = false; break; }
    }

    if(flag)
    {
        for(int j=2;j<=n;j++)
        {
            if(arr[j] == 999'999'999) cout << -1 <<endl;
            else cout << arr[j] <<endl;
        }
    }
    else
    {
        cout << -1;
    }
    
    
    
}