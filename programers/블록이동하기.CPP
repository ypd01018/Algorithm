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
    int y1, x1, y2,  x2, d1, d2;
}robot;
int lft_d(int d) {return(d+7)%4;}
int rght_d(int d) {return (d+1)%4;}

bool go_check(robot_ a,vector<vector<int>> board)
{
    if(a.y1<0 || a.y2<0 || a.x1<0 || a.x2<0 || a.y1>=board.size() || a.y2>=board.size() || a.x1>=board.size()||a.x2>=board.size()) return false;
    if(board[a.y1][a.x1] || board[a.y2][a.x2]) return false;
    return true;
}
bool true_move(robot_ a,vector<vector<int>> board,int d)
{
    a.y1 += dy[d]; a.y2 += dy[d];
    a.x1 += dx[d]; a.x2 += dx[d];
    if(!go_check(a,board)) return false;
    return true;
}
robot_ go_move(robot_ a,int d)// true_move 후 사용
{
    a.y1 += dy[d]; a.y2 += dy[d];
    a.x1 += dx[d]; a.x2 += dx[d];
    return a;
}

bool true_rotate_one(robot_ a,int rotate_d,vector<vector<int>> board)
{
    int d = a.d1;
    int dia_y = a.y1 + dia_dy[d][rotate_d], dia_x = a.x1 + dia_dx[d][rotate_d];
    if(dia_y<0 || dia_x<0 || dia_y>=board.size() || dia_x>=board.size()) return false;
    if(board[dia_y][dia_x]) return false;
    a.y1 += rotate_dy[d][rotate_d]; a.x1 += rotate_dx[d][rotate_d];
    if(!go_check(a,board)) return false;
    return true;
}
bool true_rotate_two(robot_ a,int rotate_d,vector<vector<int>> board)
{
    int d = a.d2;
    int dia_y = a.y2 + dia_dy[d][rotate_d], dia_x = a.x2 + dia_dx[d][rotate_d];
    if(dia_y<0 || dia_x<0 || dia_y>=board.size() || dia_x>=board.size()) return false;
    if(board[dia_y][dia_x]) return false;
    a.y2 += rotate_dy[d][rotate_d]; a.x2 += rotate_dx[d][rotate_d];
    if(!go_check(a,board)) return false;
    return true;
}
robot_ rotate_one(robot_ a,int rotate_d1,int rotate_d2)
{
    int d = a.d1;
    a.y1 += rotate_dy[d][rotate_d1];
    a.x1 += rotate_dx[d][rotate_d1];
    a.d1 = rotate_d1;
    a.d2 = rotate_d2;
    return a;
}
robot_ rotate_two(robot_ a,int rotate_d1,int rotate_d2)
{
    int d = a.d2;
    a.y2 += rotate_dy[d][rotate_d2];
    a.x2 += rotate_dx[d][rotate_d2];
    a.d1 = rotate_d1;
    a.d2 = rotate_d2;
    return a;
}
void print_robot(robot_ a)
{
    cout << "y1:" <<a.y1 << " x1:" << a.x1 << " y2:" << a.y2 << " x2:" << a.x2 << endl;
}
queue<pair<robot_,int> > q;
int solution(vector<vector<int>> board) 
{
    robot.d1=3; robot.d2=1;
    robot.y1=0; robot.x1=0;
    robot.y2=0; robot.x2=1;
    q.push({robot,0});
    visited[0][0][0][1]=1;
    while(!q.empty())
    {
        robot_ a = q.front().first; int sec = q.front().second; q.pop();
        // cout << sec << endl;
        if(a.y1 == board.size()-1 && a.x1 == board.size()-1) return sec;
        if(a.y2 == board.size()-1 && a.x2 == board.size()-1) return sec;
        //상하좌우 이동
        for(int i=0;i<4;i++)
        {
            // cout << "go:" << i << endl; 
            if(!true_move(a,board,i)) continue; 
            robot_ new_robot=go_move(a,i);
            if(visited[new_robot.y1][new_robot.x1][new_robot.y2][new_robot.x2]) continue;
            visited[new_robot.y1][new_robot.x1][new_robot.y2][new_robot.x2] = 1;
            q.push({new_robot,sec+1});
        }
        //one 기준 좌,우 회전
        // cout << "one_lft\n"; 
        if(true_rotate_one(a,lft_d(a.d1),board))
        {
            robot_ new_robot = rotate_one(a,lft_d(a.d1),lft_d(a.d2));
            if(!visited[new_robot.y1][new_robot.x1][new_robot.y2][new_robot.x2])
            {
                visited[new_robot.y1][new_robot.x1][new_robot.y2][new_robot.x2] = 1;
                q.push({new_robot,sec+1});
            }
        } 
        // cout <<"one_rght\n";
        if(true_rotate_one(a,rght_d(a.d1),board))
        {
            robot_ new_robot = rotate_one(a,rght_d(a.d1),rght_d(a.d2));
            if(!visited[new_robot.y1][new_robot.x1][new_robot.y2][new_robot.x2])
            {
                visited[new_robot.y1][new_robot.x1][new_robot.y2][new_robot.x2] = 1;
                q.push({new_robot,sec+1});
            }
        }
        //two 기준 좌,우 회전
        // cout <<"two_lft\n";
        if(true_rotate_two(a,lft_d(a.d2),board))
        {
            robot_ new_robot = rotate_two(a,lft_d(a.d1),lft_d(a.d2));
            if(!visited[new_robot.y1][new_robot.x1][new_robot.y2][new_robot.x2])
            {
                visited[new_robot.y1][new_robot.x1][new_robot.y2][new_robot.x2] = 1;
                q.push({new_robot,sec+1});
            }
        }
        // cout << "two_rght\n"; 
        if(true_rotate_two(a,rght_d(a.d2),board))
        {
            robot_ new_robot = rotate_two(a,rght_d(a.d1),rght_d(a.d2));
            if(!visited[new_robot.y1][new_robot.x1][new_robot.y2][new_robot.x2])
            {
                visited[new_robot.y1][new_robot.x1][new_robot.y2][new_robot.x2] = 1;
                q.push({new_robot,sec+1});
            }
        }
    }
    int answer;
    return answer;
}
void print_test(robot_ test_robot, vector<vector<int>> board)
{
    cout << "-----------------------------------\n";
    board[test_robot.y1][test_robot.x1]=2;
    board[test_robot.y2][test_robot.x2]=3;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            cout << board[i][j] << ' '; 
        }cout << endl;
    }
    cout << endl;
}
int main()
{
    vector<vector<int>> board = 
    {
        {0, 0, 0, 0, 0, 0}, //{0, 0, 0, 0, 0, 0}
        {0, 0, 0, 1, 0, 0}, //{0, 0, 0, 1, 0, 0}
        {0, 0, 0, 0, 0, 0}, //{0, 0, 2, 3, 0, 0}
        {0, 0, 0, 1, 0, 0}, //{0, 0, 0, 1, 0, 0}
        {0, 0, 0, 0, 0, 0}, //{0, 0, 0, 0, 0, 0}
        {0, 0, 0, 0, 0, 0}, //{0, 0, 0, 0, 0, 0}
    };
    robot_ test_robot;
    test_robot.d1 = 3; test_robot.d2=1;
    test_robot.y1 = 2; test_robot.x1=2;
    test_robot.y2 = 2; test_robot.x2=3;
    //print_test(test_robot,board);
    if(true_rotate_two(test_robot,rght_d(test_robot.d2),board)) print_test(rotate_two(test_robot,rght_d(test_robot.d1),rght_d(test_robot.d2)),board);
    // print_test(rotate_one(test_robot,rght_d(test_robot.d1),rght_d(test_robot.d2)),board);
    // print_test(rotate_two(test_robot,lft_d(test_robot.d1),lft_d(test_robot.d2)),board);
    // print_test(rotate_two(test_robot,rght_d(test_robot.d1),rght_d(test_robot.d2)),board);

    //cout << solution(board);
}