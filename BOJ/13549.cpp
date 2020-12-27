#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,K,arr[200'005],dx[3]={0,-1,+1};
bool visited[200'005];
queue<int> q;
void sol()
{
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        if(x == K) return;
        for(int i=0;i<3;i++)
        {
            int nx;
            if(!i) 
            {
                nx = 2*x;
                if(nx<0 || nx > 2*max(N,K) || visited[nx]) continue;
                arr[nx] = arr[x];
            }
            else
            {
                nx = x+dx[i];
                if(nx<0|| nx > 2*max(N,K) || visited[nx]) continue;
                arr[nx] = arr[x]+1;
            }
            visited[nx]=1;
            q.push(nx);
        }       
    }
}
void test()
{
    cout << endl;
    for(int i=0;i< 30 ; i++)
    {
        cout << i <<": " << arr[i] << endl;
    }
}
int main()
{
    cin >> N >> K;
    q.push(N);
    visited[N]=1;
    sol();
    cout << arr[K];
    //test();
}