#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,parent[202],arr[1002];
void init()
{
    for(int i=1;i<=N;i++) parent[i]=i;
}
int find(int a)
{
    if(parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}
void uni(int a, int b)
{
    a=find(a);
    b=find(b);

    parent[b] = a;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    init();
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            bool connect; cin >> connect;
            if(connect) uni(i,j);
        }
    }

    for(int i=0;i<M;i++)
    {
        cin >> arr[i];
    }

    for(int i=0;i<M-1;i++)
    {
        if(find(arr[i])!=find(arr[i+1]))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}