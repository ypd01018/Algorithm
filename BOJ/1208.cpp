#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,S,arr[42],ans,visited[42];
void DFS(int n, int total)
{
    if(n==N) 
    {
        if(total==S) ans++;
        return;
    }//for(int i=0;i<N;i++) cout << visited[i]; cout<< endl;
    for(int i=0;i<N;i++)
    {
        if(visited[i]) continue;
        visited[i]=1;
        DFS(n+1,total+arr[i]);
        visited[i]=0;
    }
}
int main()
{
    cin >> N >> S;
    for(int i=0;i<N;i++) cin >> arr[i];
    DFS(0,0);
    cout << ans;
}