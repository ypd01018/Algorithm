#include<iostream>
#include<memory.h>
#include<algorithm>
#include<limits.h>
#define endl "\n"
using namespace std;
const int mid = 250;
const int limit = 500;
int mat[500][500],state[500][500],sec[500][500],N,M,K,dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},mn_y=INT_MAX,mx_y=-1,mn_x=INT_MAX,mx_x=-1;
// state -> 0:없음 1:비활성 2:활성 3:주금
void make_m(int y, int x)
{
    mx_y = max(y,mx_y); mn_y = min(y,mn_y);
    mx_x = max(x,mx_x); mn_x = min(x,mn_x);
}
void go()
{
    int st_y=mn_y,st_x=mn_x,end_y=mx_y,end_x=mx_x;
    for(int i=st_y;i<=end_y;i++)
    {
        for(int j=st_x;j<=end_x;j++)
        {
            if(state[i][j]!=2) continue;
            for(int n=0;n<4;n++)
            {
                int ny = i+dy[n], nx = j+dx[n];
                make_m(ny,nx);
                if(state[ny][nx]==2 || state[ny][nx]==3) continue;
                if((state[ny][nx]==1 && (mat[ny][nx]+1)==sec[ny][nx] )||state[ny][nx]==0)
                {
                    if(mat[ny][nx]<mat[i][j])
                    {
                        state[ny][nx]=1;
                        mat[ny][nx]=mat[i][j];
                        sec[ny][nx]=mat[ny][nx]+1;
                    }
                }
            }
            
        }
    }
    for(int i=mn_y;i<=mx_y;i++)
    {
        for(int j=mn_x;j<=mx_x;j++)
        {
            if(state[i][j]==1)
            {
                if(!(--sec[i][j])) 
                {
                    state[i][j]=2;
                    sec[i][j]=mat[i][j];
                }
            }
            else if(state[i][j]==2)
            {
                if(!(--sec[i][j])) 
                {
                    state[i][j]=3;
                }
            }
        }
    }
}
int sol()
{
    mn_y=INT_MAX;mx_y=-1;mn_x=INT_MAX;mx_x=-1;
    memset(mat,0,sizeof(mat)); memset(state,0,sizeof(state)); memset(sec,0,sizeof(sec));
    cin >> N >> M >> K;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int y = i+mid-(2/N), x = j+mid-(2/N);
            make_m(y,x);
            cin >> mat[y][x]; sec[y][x]=mat[y][x];if(mat[y][x]) state[y][x]=1;
        }
    }
    for(int t=1;t<=K;t++) 
    {
        go();
    }
    int cnt=0;
    for(int i=mn_y;i<=mx_y;i++)
    {
        for(int j=mn_x;j<=mx_x;j++)
        {
            if(state[i][j]==1 || state[i][j]==2) cnt++;
        }
    }
    return cnt;

}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << '#' << test_case <<' '<<sol()<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}