#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
int visited[102][102][102][102];
int dia_dy[4][4]= //대각선 좌표
{
    {9,0,9,0}, //좌3, 우1
    {-1,9,1,9},//좌0, 우2
    {9,0,9,0},//좌1, 우3
    {-1,9,1,9}//좌2,우0
};
int dia_dx[4][4]= //대각선 좌표
{
    {9,1,9,-1}, //좌3, 우1
    {0,9,0,9},//좌0, 우2
    {9,1,9,-1},//좌1, 우3
    {0,9,0,9}//좌2,우0};
};
int rotate_dy[4][4]=
{
    {9,1,9,1},
    {-1,9,1,9},
    {9,-1,9,-1},
    {-1,9,1,9}
};
int rotate_dx[4][4]=
{
    {9,1,9,-1},
    {-1,9,-1,9},
    {9,1,9,-1},
    {1,9,1,9}
};
struct robot_
{
    int y[2], x[2], d[2];
}robot;
int lft_d(int d) {return(d+7)%4;}
int rght_d(int d) {return (d+1)%4;}

bool go_check(robot_ a,vector<vector<int>> board)
{
    for(int i=0;i<2;i++)
    {
        if(a.y[i]<0|| a.x[i]<0 || a.y[i]>=board.size()|| a.x[i]>=board.size()) return false;
        if(board[a.y[i]][a.x[i]]) return false;
    }
    return true;
}
bool true_move(robot_ a,vector<vector<int>> board,int d)
{
    for(int i=0;i<2;i++)
    {
        a.y[i] += dy[d];
        a.x[i] += dx[d];
    }
    if(!go_check(a,board)) return false;
    return true;
}
robot_ go_move(robot_ a,int d)// true_move 후 사용
{
    for(int i=0;i<2;i++)
    {
        a.y[i] += dy[d];
        a.x[i] += dx[d];
    }
    return a;
}

bool true_rotate(robot_ a,int num,int rotate_d,vector<vector<int>> board)
{
    int d = a.d[num];
    int dia_y = a.y[num] + dia_dy[d][rotate_d], dia_x = a.x[num] + dia_dx[d][rotate_d];
    if(dia_y<0 || dia_x<0 || dia_y>=board.size() || dia_x>=board.size()) return false;
    if(board[dia_y][dia_x]) return false;
    a.y[num] += rotate_dy[d][rotate_d]; a.x[num] += rotate_dx[d][rotate_d];
    if(!go_check(a,board)) return false;
    return true;
}
robot_ rotate(robot_ a,int num,int rotate_d1,int rotate_d2)
{
    int d = a.d[num];
    a.y[num] += rotate_dy[d][rotate_d1];
    a.x[num] += rotate_dx[d][rotate_d1];
    a.d[0] = rotate_d1;
    a.d[1] = rotate_d2;
    return a;
}
queue<pair<robot_,int> > q;
int solution(vector<vector<int>> board) 
{
    robot.d[0]=3; robot.d[1]=1;
    robot.y[0]=0; robot.x[0]=0;
    robot.y[1]=0; robot.x[1]=1;
    q.push({robot,0});
    visited[0][0][0][1]=1;
    while(!q.empty())
    {
        robot_ a = q.front().first; int sec = q.front().second; q.pop();
        if(a.y[0] == board.size()-1 && a.x[0] == board.size()-1) return sec;
        if(a.y[1] == board.size()-1 && a.x[1] == board.size()-1) return sec;
        //상하좌우 이동
        for(int i=0;i<4;i++)
        {
            if(!true_move(a,board,i)) continue; 
            robot_ new_robot=go_move(a,i);
            if(visited[new_robot.y[0]][new_robot.x[0]][new_robot.y[1]][new_robot.x[1]]) continue;
            visited[new_robot.y[0]][new_robot.x[0]][new_robot.y[1]][new_robot.x[1]] = 1;
            q.push({new_robot,sec+1});
        }
        //좌,우 회전
        for(int i=0;i<2;i++)
        {
            if(true_rotate(a,i,lft_d(a.d[i]),board))
            {
                robot_ new_robot = rotate(a,i,lft_d(a.d[0]),lft_d(a.d[1]));
                if(!visited[new_robot.y[0]][new_robot.x[0]][new_robot.y[1]][new_robot.x[1]])
                {
                    visited[new_robot.y[0]][new_robot.x[0]][new_robot.y[1]][new_robot.x[1]] = 1;
                    q.push({new_robot,sec+1});
                }
            } 
            if(true_rotate(a,i,rght_d(a.d[i]),board))
            {
                robot_ new_robot = rotate(a,i,rght_d(a.d[0]),rght_d(a.d[1]));
                if(!visited[new_robot.y[0]][new_robot.x[0]][new_robot.y[1]][new_robot.x[1]])
                {
                    visited[new_robot.y[0]][new_robot.x[0]][new_robot.y[1]][new_robot.x[1]] = 1;
                    q.push({new_robot,sec+1});
                }
            }
        }

    }
    int answer;
    return answer;
}
