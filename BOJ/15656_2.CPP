#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,arr[10],ans[10],visit[10],idx;
void DFS()
{
    if(idx==M)
    {
        for(int i=0;i<M;i++) cout << ans[i] << ' ';
        cout << endl;
        return;
    }
    for(int i=0;i<N;i++)
    {
        //if(visit[i]) continue;
        ans[idx] = arr[i];
        idx++;
        visit[i]=1;
        DFS();
        visit[i]=0;
        idx--;
    }
}
int main()
{
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> arr[i];
    sort(arr,arr+N);
    DFS();
}