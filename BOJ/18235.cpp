#include<bits/stdc++.h>
#define endl "\n"
#define mp make_pair
#define f first
#define s second
using namespace std;
int arr[30][500'010],N,A,B,nxt[2]={-1,1},visited[30][500'010],ans=-1;
queue<pair<int,int> > q;
queue<pair<int,int> > q2;
int main()
{
    cin >> N >> A >> B;
    arr[0][A] = 1;
    q.push(mp(A,0));
    while(!q.empty())
    {
        int a = q.front().f,b = q.front().s; q.pop();
        for(int i=0;i<2;i++)
        {
            int nxt_a = (a+nxt[i]*pow(2,b));
            if(nxt_a<1 || nxt_a >N || arr[b+1][nxt_a]) continue;
            arr[b+1][nxt_a] = 1;
            q.push(mp(nxt_a,b+1));
        }
    }
    q2.push(mp(B,0));
    visited[0][B]=1;
    while(!q2.empty())
    {
        int a = q2.front().f, b = q2.front().s; q2.pop();
        for(int i=0;i<2;i++)
        {
            int nxt_a = (a+nxt[i]*pow(2,b));
            if(nxt_a<1 || nxt_a >N || visited[b+1][nxt_a]) continue;
            visited[b+1][nxt_a]=1;
            if(arr[b+1][nxt_a])
            {
                cout << b+1;
                return 0;
            }
            q2.push(mp(nxt_a,b+1));
        }
    }
    cout << ans;


    
    

}