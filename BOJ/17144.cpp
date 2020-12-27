#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int R,C,T,mat[55][55],d[55][55],dy[5]={0,-1,0,1,0},dx[5]={0,0,1,0,-1};
pair<int,int> prufer;
vector<pair<int,int>> v[2];
void make_dmap()
{
    int y = prufer.first, x = prufer.second;
    for(int i=1;i<C-1;i++) 
    {
        d[y][i]=2; 
        //v[1].push_back({y,i});
        d[y-1][i]=2; 
        //v[0].push_back({y-1,i});
    }
    for(int i=y;i<R-1;i++) d[i][C-1]=3;//v[1].push_back({i,C-1});//
    for(int i=C-1;i>0;i--) d[R-1][i]=4;//v[1].push_back({R-1,i});//
    for(int i=R-1;i>y;i--) d[i][0]=1;//v[1].push_back({i,0});//

    for(int i=y-1;i>0;i--) d[i][C-1]=1;//v[0].push_back({i,C-1});//
    for(int i=C-1;i>0;i--) d[0][i]=4;//v[0].push_back({0,i});//
    for(int i=0;i<y-1;i++) d[i][0]=3;//v[0].push_back({i,0});//
}
void dust()
{
    int new_mat[55][55];
    memset(new_mat,0,sizeof(new_mat));
    new_mat[prufer.first][prufer.second]=-1;
    new_mat[prufer.first-1][prufer.second]=-1;

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(mat[i][j]!=0 && mat[i][j]!=-1)
            {
                int dust_size = mat[i][j]/5;
                for(int n=1;n<5;n++)
                {
                    int ny = i+dy[n],nx=j+dx[n];
                    if(ny >=0 && nx >=0 && ny <R && nx <C && mat[ny][nx]!=-1)
                    {
                        new_mat[ny][nx]+=dust_size;
                        mat[i][j] -= dust_size;
                    }
                }
                if(mat[i][j]>=0) new_mat[i][j]+=mat[i][j];
            }
        }
    }

    memcpy(mat,new_mat,sizeof(new_mat));
}
void act_prufer()
{
    int new_mat[55][55];
    memset(new_mat,0,sizeof(new_mat));
    new_mat[prufer.first][prufer.second]=-1;
    new_mat[prufer.first-1][prufer.second]=-1;

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(mat[i][j]==-1) continue;
            if(d[i][j]==0) new_mat[i][j]=mat[i][j];
            else
            {
                int ny=i+dy[d[i][j]],nx=j+dx[d[i][j]];
                if(mat[ny][nx]!=-1) new_mat[ny][nx]=mat[i][j];
            }
             
        }
    }
    memcpy(mat,new_mat,sizeof(new_mat));

}
void dust_calc()
{
    int cnt=0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(mat[i][j]==-1)continue;
            cnt += mat[i][j];
        }
    }
    cout << cnt;
}
void print_test()
{
    cout << "---------------------start-----------------------------" << endl;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "---------------------e n d-----------------------------"<< endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C >> T;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]==-1) prufer={i,j};
        }
    }
    
    make_dmap();
    for(int i=0;i<T;i++)
    {
        dust();//확산
        act_prufer();//이동
    }
    dust_calc();

}