#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
using namespace std;
int N,W,H,mat[18][18],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},cnt,mn=99999999;
void print_test()
{
    cout << "-------------------------------mat--------------------------"<<endl;
    for(int i=H-1;i>=0;i--)
    {
        for(int j=0;j<W;j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }cout << endl;
}
int broken(int y,int x)
{
    queue<pair<int,pair<int,int> > > q;
    q.push(make_pair(mat[y][x],make_pair(y,x))); mat[y][x]=0; cnt--;
    while(!q.empty())
    {
        int y_=q.front().second.first, x_=q.front().second.second, range = q.front().first; q.pop();
        for(int i=0;i<4;i++)
        {
            int ny = y_, nx = x_;
            for(int j=1;j<range;j++)
            {
                ny += dy[i]; nx += dx[i];
                if(ny<0 || nx<0 || ny >=H || nx >=W) break;
                if(!mat[ny][nx]) continue;
                q.push(make_pair(mat[ny][nx],make_pair(ny,nx)));
                mat[ny][nx]=0; cnt--;
            }
        }
    }
    mn = min(cnt,mn);
}
int check(int x)
{
    for(int i=H-1;i>=0;i--)
    {
        if(mat[i][x]>0) return i;
    }
    return -1;
}
void push(int x)
{
    for(int i=0;i<H;i++)
    {
        if(mat[i][x]) continue;
        for(int j=i;j<H;j++)
        {
            if(!mat[j][x]) continue;
            mat[i][x]=mat[j][x];
            mat[j][x]=0;
            break;
        }
    }
}

void go(int x,int n)
{
    if(n==N) {return;}
    int y = check(x);
    if(y==-1) {return;}
    

    int pre_origin[18][18],origin[18][18],origin_cnt=cnt; 
    memcpy(pre_origin,mat,sizeof(mat));
    broken(y,x);
    for(int i=0;i<W;i++) push(i);
    memcpy(origin,mat,sizeof(mat)); 
    for(int i=0;i<W;i++)
    {
        go(i,n+1);
        memcpy(mat,origin,sizeof(mat));
    }
    memcpy(mat,pre_origin,sizeof(mat));
    cnt = origin_cnt;
}
void sol()
{   cnt=0;
    cin >> N >> W >> H;
    for(int i=H-1;i>=0;i--)
    {
        for(int j=0;j<W;j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]) {cnt++;}
        }
    }
    mn = cnt;
    for(int i=0;i<W;i++)
    go(i,0);
    cout << mn << endl;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << '#' << test_case <<' ';
        sol();
	}
	return 0;
}