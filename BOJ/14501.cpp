#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,tot,mx;
pair<int,int> arr[20];
bool visited[20],non[20];
void DFS(int a)
{
    if(a==n-1)
    {
        if(!visited[a] && !non[a])
        {
            tot += arr[a].second;
        }    
        mx = max(tot,mx);
        if(!visited[a] && !non[a])
        {
        tot -= arr[a].second;
        }
        return;
    }

    if(visited[a] || non[a]) return; 

    //cout <<"a:" << a << " tot:" << tot << endl;
    tot += arr[a].second;
    for(int i=a;i<a+arr[a].first;i++)
    {
        visited[i]=1;
    }
    
    for(int i=a+1;i<n;i++)
    {
        DFS(i);
    }

    tot -= arr[a].second;
    for(int i=a;i<a+arr[a].first;i++)
    {
        visited[i]=0;
    }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i].first >> arr[i].second;
        if(i+arr[i].first>n) non[i]=true;
    }
    for(int i=0;i<n;i++)
    {
        if(!non[i]) DFS(i);
    }
    cout << mx;

}