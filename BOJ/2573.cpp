#include<bits/stdc++.h>
<<<<<<< HEAD
#define endl '\n'
using namespace std;
int N,M,mat[500][500],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},visit[500][500];
vector<pair<int,int>> tmp,processing;
queue<pair<int,pair<int,int>>> q;
queue<pair<int,int>> q_local;

void go(){
    processing = tmp;
    tmp.clear();
    for(int i=0;i<processing.size();i++){
        int y = processing[i].first, x = processing[i].second;
        int cnt = mat[y][x];
        for(int n=0;n<4;n++){
            int nx = x+dx[n], ny = y+dy[n];
            if(ny<0||nx<0||ny>=N||nx>=M||mat[ny][nx]) continue;
            cnt--;
        }
        if(cnt<0) cnt=0;
        q.push({cnt,{y,x}});
        if(cnt) tmp.push_back({y,x});
    }
    while(!q.empty()){
        int y = q.front().second.first, x= q.front().second.second , cnt = q.front().first; q.pop();
        mat[y][x] = cnt;
    }

}

bool BFS(){
    memset(visit,0,sizeof(visit));
    int cnt = 0;
    for(int i=1;i<N-1;i++){
        for(int j=1;j<M-1;j++){
            if(visit[i][j] || !mat[i][j]) continue;
            cnt++;
            if(cnt>1) return true;
            q_local.push({i,j});
            visit[i][j]=1;
            while(!q_local.empty()){
                int y = q_local.front().first , x = q_local.front().second; q_local.pop();
                for(int n=0;n<4;n++){
                    int ny = y+dy[n], nx = x+dx[n];
                    if(!mat[ny][nx] || visit[ny][nx]) continue;
                    visit[ny][nx] = 1;
                    q_local.push({ny,nx});
                }
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) {
            cin >> mat[i][j];
            if(mat[i][j]) tmp.push_back({i,j});
        }
    }
    int year = 0;
    if(!tmp.size()) {cout << 0; return 0;}
    while(tmp.size()) {
        year++;
        go();
        if(BFS()) {
            cout << year;
            return 0;
        }
    }
    cout << 0;
=======
#define endl "\n"
using namespace std;
int N,M,mat[302][302],visited[302][302],dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0},down[302][302],cnt=1,n=0,zeros_check[302][302];
queue<pair<int,int>> q,zeros;
void BFS()
{
    while(!q.empty())
    {
        int y,x; tie(y,x) = q.front(); q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(ny>0 && nx > 0 && ny <N-1 && nx < M-1 && mat[ny][nx] && !visited[ny][nx])
            {
                visited[ny][nx]=1;
                q.push({ny,nx});
            }
        }
    }
}
void next_year()
{   
    while(!zeros.empty())
    {
        int y,x; tie(y,x) = zeros.front(); zeros.pop();
        zeros_check[y][x]=1;
        for(int i=0;i<4;i++)
        {
            int ny = y+dy[i], nx = x+dx[i];
            if(ny >= 0 && nx >=0 && ny <N && nx < M)
            {
                down[ny][nx]--;
            }
        }
    }

    for(int i=1;i<N-1;i++)
    {
        for(int j=1;j<M-1;j++)
        {
            mat[i][j] += down[i][j];
            if(mat[i][j] <= 0)
            {   
                mat[i][j]=0;
                if(!zeros_check[i][j]) zeros.push({i,j});
            }
        }
    }

}
void sol()
{
    while(1)
    {
        cnt=0;
        memset(visited,0,sizeof(visited));
        for(int i=1;i<N-1;i++)
        {
            for(int j=1;j<M-1;j++)
            {
                if(mat[i][j] && !visited[i][j])
                {
                    visited[i][j]=1;
                    q.push({i,j});
                    BFS();
                    cnt++;  
                }

                if(cnt>1) 
                {
                    cout << n;
                    return;
                }
            }
        }
        if(cnt==0) 
        {
            cout << 0;
            return;
        }
        next_year();
        n++;
    }

}
int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int tmp;
            cin >> tmp;
            mat[i][j]=tmp;
            if(tmp==0) zeros.push({i,j});
        }
    }
    sol();
>>>>>>> c970bb23ae158ddb0c279d0af13d5172eedb711b
}