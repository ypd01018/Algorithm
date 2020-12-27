#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int mat[12][12],input[12][12],N,M,visited[12][12],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},root[10],n_island;
queue<pair<int,int>> q;
vector<pair<int,pair<int,int>>> v;
void make_mat()
{
    int cnt=1;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(input[i][j] && !visited[i][j])
            {
                q.push({i,j});
                mat[i][j]=cnt;
                visited[i][j]=1;

                while(!q.empty())
                {
                    int x=q.front().second,y=q.front().first; q.pop();
                    for(int n=0;n<4;n++)
                    {
                        int ny = y+dy[n], nx = x+dx[n];
                        if(ny>=0 && nx >=0 && ny <N && nx <M && input[ny][nx] && !visited[ny][nx])
                        {
                            q.push({ny,nx});
                            visited[ny][nx]=1;
                            mat[ny][nx]=cnt;
                        }
                    }
                }
                cnt++;
            }
        }
    }
    n_island = cnt-1;
    //cout << endl;
    // for(int i=0;i<N;i++)
    // {
    //     for(int j=0;j<M;j++)
    //     {
    //         cout << mat[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}
void dis_island()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(mat[i][j])
            {
                for(int n=0;n<4;n++)
                {
                    int ny = i+dy[n], nx = j+dx[n], dis=0;
                    if(nx >= 0 && ny >=0 && ny <N && nx<M && !mat[ny][nx])
                    {
                        while(ny >=0 && nx >=0 && ny <N && nx<M)
                        {
                            ny = ny+dy[n];
                            nx = nx+dx[n];
                            dis++;
                            if(mat[ny][nx]) break;
                        }
                        if(dis>=2 && nx >= 0 && ny >=0 && ny <N && nx<M)
                        {
                            //cout << dis<<endl;
                            int start = mat[i][j];
                            int end = mat[ny][nx];
                            v.push_back({dis,{start,end}});
                            //cout << "make_dis:" << i<<','<<j << "   " << ny << ',' << nx << "    "<< dis<< endl;
                        }
                    }
                }
            }
        }
    }
}
void init()
{
    for(int i=0;i<10;i++) root[i]=i;
}
int find(int a)
{
    if(a==root[a]) return a;
    else return root[a]=find(root[a]);
}
void uni(int a, int b)
{
    a=root[a];
    b=root[b];
    root[b] = a;
}
int main()
{
    cin >> N >> M;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> input[i][j];
        }
    }

    make_mat();
    dis_island();
    sort(v.begin(),v.end());
    int tot=0,cnt=0;
    init();
    for(int i=0;i<v.size();i++)
    {
        int start = v[i].second.first;
        int end = v[i].second.second;
        if(find(start)!=find(end))
        {
        //cout << i << ':'<<v[i].first<<"    "<< v[i].second.first << ',' <<v[i].second.second<<endl;
            tot += v[i].first;
            uni(start,end);
            cnt++;
        }
        if(cnt == n_island-1)
        {
            break;
        }
    }

    if(cnt == n_island-1) cout << tot;
    else cout << -1;


    
}