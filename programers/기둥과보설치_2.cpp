#include <string>
#include <vector>
#include <iostream>
using namespace std;
int mat_col[102][102], mat_bo[102][102];
bool check_col(int y, int x)
{
    if(y==0)return true;
    if(y>0 && mat_col[y-1][x]) return true;
    if(mat_bo[y][x]) return true;
    if(x>0 && mat_bo[y][x-1]) return true;
    return false;
}
bool check_bo(int y, int x)
{
    if((mat_col[y-1][x]))return true;
    if(mat_col[y-1][x+1])return true;
    if( mat_bo[y][x+1] && (x>0 && mat_bo[y][x-1]) ) return true;
    return false;
}
void make_column(int y,int x)
{
   if(check_col(y,x)) mat_col[y][x]=1;
}
void make_bo(int y,int x)
{
    if(check_bo(y,x))mat_bo[y][x]=1;
}
void delete_column(int y,int x)
{
    bool flag = true;
    mat_col[y][x]=0;
    if(flag && mat_col[y+1][x]) flag = check_col(y+1,x);
    if(flag && x>0 && mat_bo[y+1][x-1]) flag = check_bo(y+1,x-1);
    if(flag && mat_bo[y+1][x]) flag = check_bo(y+1,x);
    if(!flag)mat_col[y][x]=1;
    
}
void delete_bo(int y,int x)
{
    bool flag = true;
    mat_bo[y][x]=0;
    if(flag && mat_col[y][x]) flag = check_col(y,x);
    if(flag && mat_col[y][x+1]) flag = check_col(y,x+1);
    if(flag && x>0 && mat_bo[y][x-1]) flag = check_bo(y,x-1);
    if(flag && mat_bo[y][x+1]) flag = check_bo(y,x+1);
    if(!flag) mat_bo[y][x]=1;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) 
{
    for(int i=0;i<build_frame.size();i++)
    {
        int x = build_frame[i][0], y=build_frame[i][1];
        int a = build_frame[i][2],b = build_frame[i][3];
        if(a==0)
        {
            if(b) make_column(y,x);
            else delete_column(y,x);
        }
        else
        {
            if(b) make_bo(y,x);
            else delete_bo(y,x);
        }
    }
    vector<vector<int>> answer;
    for(int i=0;i<102;i++)
    {
        for(int j=0;j<102;j++)
        {
            if(mat_col[j][i])
            {
                vector<int> push={i,j,0};
                answer.push_back(push);
            }
            if(mat_bo[j][i])
            {
                vector<int> push={i,j,1};
                answer.push_back(push);
            }
        }
    }
    return answer;
}