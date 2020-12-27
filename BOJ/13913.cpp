#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,K,dx[3]={0,-1,+1},prv;
pair<int,int> arr[200'005];
bool visited[200'005];
queue<int> q;
stack<int> stk;
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
                arr[nx].first = arr[x].first+1;
            }
            else
            {
                nx = x+dx[i];
                if(nx<0|| nx > 2*max(N,K) || visited[nx]) continue;
                arr[nx].first = arr[x].first+1;
            }
            arr[nx].second = x;
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
        cout << i <<": " << arr[i].first << endl;
    }
}
void course()
{
    while(prv!=N)
    {
        stk.push(arr[prv].second);
        prv = arr[prv].second;
    }
    while(!stk.empty())
    {
        cout << stk.top() << ' ';
        stk.pop();
    }
}
int main()
{
    cin >> N >> K;
    q.push(N);
    visited[N]=1;
    sol();
    cout << arr[K].first << endl;
    prv = K;    
    stk.push(K);
    course();

    //test();
}