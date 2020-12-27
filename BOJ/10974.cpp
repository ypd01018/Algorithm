#include<iostream>
#include<algorithm>
#define endl "\n"
using namespace std;
int N,arr[10],ans[10],idx,visit[10],cnt;
void DFS()
{
    if(cnt==N)
    {
        for(int i=0;i<N;i++) cout << ans[i]<<' '; cout << endl;
        return;
    }
    for(int i=0;i<N;i++)
    {
        if(!visit[i])
        {
            ans[cnt]=arr[i];
            cnt++;
            visit[i]=1;
            DFS();
            cnt--;
            visit[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) arr[i]=i+1;
    DFS();
}