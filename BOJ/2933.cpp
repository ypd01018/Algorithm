#include<bits/stdc++.h>
#define endl "\n"
#define mp make_pair 
using namespace std;
int R,C,N,dy[4]={0,0,-1,1},dx[4]={1,-1,0,0},visited[102][102];
char mat[102][102];
vector<pair<int,int> > v;
void print_test()
{

    for(int i=R;i>0;i--)
    {
        for(int j=1;j<=C;j++)
        {
            cout << mat[i][j];
        }cout<<endl;
    }
}
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first < b.first) return true;
    else if(a.first>b.first) return false;
    else
    {
        if(a.second < b.second) return true;
        else return false;
    } 
}
void broken(int h,int d) // 0:왼쪽-> 오른쪽, 1:왼쪽 <- 오른쪽
{
    int i;
    if(d) i=C;
    else i=1;
    for(i;i<=C&&i>0;i+=dx[d]) if(mat[h][i]=='x') break;
    if(!i||i==C+1) return;
    mat[h][i]='.';
}
void go_down()
{
    sort(v.begin(),v.end(),cmp);
    int check[102][102]={0};
    int mn =1000;
    for(int i=0;i<v.size();i++)
    {
        int y = v[i].first, x = v[i].second;
        check[y][x]=1;
        int ny = y-1, nx = x;
        if(mat[ny][nx]=='x') continue;
        for(int j=ny; j>=0;j--)
        {
            if(mat[j][nx]=='x' || j == 0)
            {
                if(check[j][nx]) break;
                int val;
                if(j==0) val=y-1; else val = (y-j)-1;
                // cout << y << ',' << x << "  " << val<< endl;
                mn = min(mn,val);
                break;
            }
        }
    }
    for(int i=0;i<v.size();i++)
    {
        int y = v[i].first, x = v[i].second;
        mat[y][x]='.';
        mat[y-mn][x]='x';
    }
}
void go_down_check()
{
    memset(visited,0,sizeof(visited));
    for(int i=R;i>0;i--)
    {
        for(int j=1;j<=C;j++)
        {
            if(!visited[i][j] && mat[i][j]=='x')
            {
                v.clear(); queue<pair<int,int> > q;
                q.push(mp(i,j)); visited[i][j]=1; v.push_back(mp(i,j));
                bool flag = true;

                while(!q.empty())
                {
                    int y = q.front().first, x=q.front().second; q.pop();
                    if(y-1==0) flag = false;
                    for(int n=0;n<4;n++)
                    {
                        int ny=y+dy[n], nx=x+dx[n];
                        if(ny<=0 || nx <=0 || ny>R || nx>C || visited[ny][nx] || mat[ny][nx]=='.') continue; 
                        q.push(mp(ny,nx)); visited[ny][nx]=1; v.push_back(mp(ny,nx));
                    }
                }

                if(flag==false) continue;
                go_down();
                return;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> R >> C;
    for(int i=R;i>0;i--)
    {
        for(int j=1;j<=C;j++)
        {
            cin >> mat[i][j];
        }
    }
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int h; cin >> h;
        broken(h,(i%2));
        // cout <<"after_broken"<<endl; print_test();
        go_down_check();
        // cout <<"after go down"<<endl; print_test();
    }
    print_test();

}