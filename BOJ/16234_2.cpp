#include<iostream>
#include<queue>
#include<algorithm>
#define endl "\n"
#define mp make_pair
#define f first
#define s second
using namespace std;
int N,L,R,mat[55][55],dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
int abs(int a, int b)
{
    if(a>b) swap(a,b);
    return a-b;
}
void print_test(int ans)
{
    cout << ans << endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << mat[i][j] << ' ';
        }cout << endl;
    }
}
int main()
{
    cin >> N >> L >> R;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> mat[i][j];
        }
    }
    int ans=0;
    while(1)
    {
        int visited[55][55]={0};
        bool flag = true;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(visited[i][j]) continue;
                visited[i][j]=1;
                queue<pair<int,int> > q ,q2;
                q.push(mp(i,j)); q2.push(mp(i,j));
                int total = 0, cnt=0;
                while(!q.empty())
                {
                    int y = q.front().first, x = q.front().second; q.pop();
                    total += mat[y][x]; cnt++;
                    for(int n=0;n<4;n++)
                    {
                        int ny = y +dy[n], nx = x+dx[n];
                        if(ny<0 || nx<0 || ny>=N || nx>=N || visited[ny][nx]) continue;
                        int val = abs(mat[y][x]-mat[ny][nx]);
                        if(val<L || val>R) continue;
                        visited[ny][nx]=1;
                        q.push(mp(ny,nx)); q2.push(mp(ny,nx));
                    }
                }
                int val = total/cnt;
                if(q2.size()>1) flag = false;
                while(!q2.empty())
                {
                    int y = q2.front().first, x=q2.front().second; q2.pop();
                    mat[y][x] = val;
                }
            }
        }
        if(flag) break;
        print_test(ans+1);
        ans++;
    }
    cout << ans;
}