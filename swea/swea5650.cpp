#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#define endl "\n"
#define mp make_pair 
using namespace std;
int N,mat[102][102],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},score_mat[102][102][4];
vector<pair<int,int>> hall[13];
int ret_d(int block,int d)
{
    if(block==1)
    {
        if(d==0) return 2;
        else if(d==1) return 3;
        else if(d==2) return 1;
        else return 0; 
    }
    else if(block==2)
    {
        if(d==0) return 1;
        else if(d==1) return 3;
        else if(d==2) return 0;
        else if(d==3) return 2;
    }
    else if(block==3)
    {
        if(d==0) return 3;
        else if(d==1) return 2;
        else if(d==2) return 0;
        else return 1;
    }
    else if(block==4)
    {
        if(d==0) return 2;
        else if(d==1) return 0;
        else if(d==2) return 3;
        else return 1;
    }
    else
    {
        return (d+2)%4;
    }
    
    
}
int go(int y,int x,int d)
{
    bool start_flag = false;
    int start_y = y, start_x = x ,score=0;
    while(1)
    {
        if(start_flag&&(start_x==x)&&(start_y==y)) break;
        if(!start_flag) start_flag = true;
        // cout <<"   "<< y <<',' << x<<endl;
        int ny,nx;
        if(y<0 ||x<0 ||y>=N ||x>=N)//벽
        {
            d = ret_d(5,d);
            ny = y+dy[d]; nx = x+dx[d];
            score++;
        }
        else if(mat[y][x]==-1)//블랙홀
        {
            break;
        }
        else if(mat[y][x]==0) //빈칸
        {
            ny=y+dy[d];nx=x+dx[d];
        }
        else if(0<mat[y][x] && mat[y][x]<6)//블록 
        {
            d = ret_d(mat[y][x],d);
            ny = y+dy[d]; nx = x+dx[d];
            score++;
        }
        else if(6<=mat[y][x])//웜홀
        {
            int num = mat[y][x];
            for(int i=0;i<hall[num].size();i++)
            {
                if(hall[num][i].first==y && hall[num][i].second==x) continue;
                ny = hall[num][i].first; nx = hall[num][i].second;
            }
            ny = ny+dy[d]; nx=nx+dx[d];
        }
        y=ny; x=nx;
    }

    return score;
}
int sol()
{   
    memset(mat,0,sizeof(mat)); memset(score_mat,-1,sizeof(score_mat)); for(int i=0;i<13;i++) hall[i].clear();
    int mx=0;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]>5)
            {
                hall[mat[i][j]].push_back(mp(i,j));
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int d=0;d<4;d++)
            {
                // cout << i << ' ' << j << ' ' << d << endl;

                if(mat[i][j]!=0) continue;
                mx = max(mx,go(i,j,d));
            }
        }
    }
    return mx;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout <<'#' << test_case <<' '<< sol() << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}