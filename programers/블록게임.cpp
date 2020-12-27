#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer;
int board_true[5][3][3]=
{
    {
        {0,1,0},
        {0,1,0},
        {1,1,0}
    },
    {
        {1,0,0},
        {1,0,0},
        {1,1,0}
    },
    {
        {1,0,0},
        {1,1,1},
        {0,0,0}
    },
    {
        {0,0,1},
        {1,1,1},
        {0,0,0}
    },
    {
        {0,1,0},
        {1,1,1},
        {0,0,0}
    },
};
pair<int,int> yx_e[5]={{3,2},{3,2},{2,3},{2,3},{2,3}};
pair<int,int> board_true_up[5][2]=
{
    {{-1,-1}, {1,0}},
    {{-1,-1}, {1,1}},
    {{0,1}, {0,2}},
    {{0,0}, {0,1}},
    {{0,0}, {0,2}}
};
bool cmp_board(int y, int x,int num,vector<vector<int>> board)
{
    int cnt=0,fig_num;
    int y_e = yx_e[num].first, x_e = yx_e[num].second;
    for(int i=y;i<y+y_e && i<board.size();i++)
    {
        for(int j=x;j<x+x_e && j<board[0].size();j++)
        {
            if(!board_true[num][i-y][j-x] || !board[i][j]) continue;
            if(!cnt) {fig_num = board[i][j]; cnt++;}
            else if(cnt>0 && board[i][j]==fig_num) cnt++;
        }
    }
    if(cnt<4) return false;
    else return true;
}
bool up_check(int y,int x,int num,vector<vector<int>> board)
{
    for(int i=0;i<2;i++)
    {
        if(board_true_up[num][i].first == -1) continue;
        int ny = y+board_true_up[num][i].first, nx = x+board_true_up[num][i].second;
        for(int j = ny;j>=0;j--)
        {
            if(board[j][nx]) return false;
        }
    }
    return true;
}
void erase(int y,int x,int num,vector<vector<int>> &board)
{
    int y_e = yx_e[num].first, x_e = yx_e[num].second;
    for(int i=y;i<y+y_e && i<board.size();i++)
    {
        for(int j=x;j<x+x_e && j<board[0].size();j++)
        {
            if(!board_true[num][i-y][j-x]) continue;
            board[i][j]=0;
        }
    }
}
bool board_check(int y, int x,vector<vector<int>> &board)
{
    for(int i=0;i<5;i++)
    {
        if(!cmp_board(y,x,i,board))continue;
        if(!up_check(y,x,i,board)) continue;
        erase(y,x,i,board);
        return true;
    }
    return false;
}
void go(vector<vector<int>> &board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            if(board_check(i,j,board)) answer++;
        }
    }
}
int solution(vector<vector<int>> board) 
{
    go(board);
    go(board);
    go(board);
    return answer;
}
int main()
{
    vector<vector<int>> board;
    board.resize(10);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            int a; cin >> a;
            board[i].push_back(a);
        }
    }
    cout << solution(board);
}