#include<iostream>
#include<vector>
using namespace std;
int N,M,d[2002][2002],visited[2002];
vector<int> graph[2002];
void DFS(int a, int b)
{
    if(b>3)
    {
        cout << 1;
        exit(0);
    }
    for(int i=0;i<graph[a].size();i++)
    {
        if(!visited[graph[a][i]])
        {
            visited[graph[a][i]]=1;
            DFS(graph[a][i],b+1);
            visited[graph[a][i]]=0;
        }
    }
}
int main()
{
    cin >> N >> M;
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<N;i++)
    {
        visited[i]=1;
        DFS(i,0);
        visited[i]=0;
    }
    cout << 0;

}
