#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,cnt,idx,arr[10],ans[10],visited[10];
void DFS(int a)
{
    if(cnt==M)
    {
        for(int i=0;i<cnt;i++) cout << ans[i] << ' '; cout << endl;
        return;
    }

    for(int i=a;i<N;i++)
    {
        if(visited[i]) continue;
        ans[cnt] = arr[i];
        cnt++;
        visited[i]=1;

        DFS(i+1);

        cnt--;
        visited[i]=0;
    }

}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++) arr[i]=i+1;
    DFS(0);
}