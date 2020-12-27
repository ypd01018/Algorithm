#include <string>
#include <vector>
#include <iostream>
using namespace std;
int mat_col[102][102], mat_bo[102][102];
bool check_col(int y, int x)
{
    if(y==0 || mat_col[y-1][x] || mat_bo[y][x] || (x>0 && mat_bo[y][x-1])) return true;
    return false;
}
bool check_bo(int y, int x)
{
    if(mat_col[y-1][x] || mat_col[y-1][x+1] || (mat_bo[y][x+1] && (x>0 && mat_bo[y][x-1]))) return true;
    return false;
}
void make_column(int y,int x)
{
   if(y==0 || mat_col[y-1][x] || mat_bo[y][x] || (x>0 && mat_bo[y][x-1])) mat_col[y][x]=1;
}
void make_bo(int y,int x)
{
    if(mat_col[y-1][x] || mat_col[y-1][x+1] || (mat_bo[y][x+1] && (x>0 && mat_bo[y][x-1])))
    {
        mat_bo[y][x]=1;
    }    
}
void delete_column(int y,int x)
{
    if(mat_col[y+1][x]) //위에 기둥 있는지
    {
        if((!mat_bo[y+1][x] && !mat_bo[y+1][x-1])) return;//기둥을 제거하고 받쳐줄 보가 없으면 제거 실패
    }
    if(mat_bo[y][x]) // 자신을 왼쪽 기둥으로 쓰고있는 보가 있는지
    {
        if(!mat_col[y][x+1] && (!mat_bo[y][x-1] || !mat_bo[y][x+1]) ) return;//보를 받칠 오른쪽 기둥도 없고, 양쪽에 하나라도 보가 없으면 제거 실패
    }
    if(mat_bo[y][x-1]) // 자신을 오른쪽 기둥으로 쓰고있는 보가 있는지
    {
        if(!mat_col[y][x-1] && (!mat_bo[y][x-2] || !mat_bo[y][x]) ) return;//보를 받칠 오른쪽 기둥도 없고, 양쪽에 하나라도 보가 없으면 제거 실패
    }
    mat_col[y][x]=0;
}
void delete_bo(int y,int x)
{
    if(mat_col[y][x])//왼쪽위에 기둥이 있을 때
    {
        if(!mat_bo[y][x-1] && !mat_col[y-1][x] ) return;//보를 제거하고 받쳐줄 왼쪽 보도 없고 밑기둥도 없으면 제거 실패
    }
    if(mat_col[y][x+1])//오른쪽 위에 기둥이 있을 때
    {
        if(!mat_bo[y][x+1] && !mat_col[y-1][x+1] ) return;//보를 제거하고 받쳐줄 오른쪽 보도 없고 밑기둥도 없으면 제거 실패
    }
    if(mat_bo[y][x-1])//왼쪽에 보가 있을 때
    {
        if(!mat_col[y-1][x-1] && !mat_col[y-1][x]) return;//보를 제거하고 받쳐줄 왼쪽 기둥도 오른쪽 기둥도 없으면 제거 실패
    }
    if(mat_bo[y][x+1])//오른쪽에 보가 있을 때
    {
        if(!mat_col[y-1][x+1] && !mat_col[y-1][x+2]) return;//보를 제거하고 받쳐줄 왼쪽 기둥도 오른쪽 기둥도 없으면 제거 실패
    }
    mat_bo[y][x]=0;
    return;
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