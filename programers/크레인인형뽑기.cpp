#include<iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<int> stk;
int answer;
void get(int a)
{
    if(!stk.empty() && stk.top()==a) 
    {
        stk.pop(); answer+=2;
    }
    else stk.push(a);
}
void go(vector<vector<int>> &board,int x)
{
    for(int i=0;i<board.size();i++)
    {
        if(!board[i][x]) continue;
        get(board[i][x]);
        board[i][x]=0;
        break;
    }
}
int solution(vector<vector<int>> board, vector<int> moves) 
{
    for(int i=0;i<moves.size();i++)
    {
        go(board,moves[i]-1);
    }
    return answer;
}

int main()
{
    vector<vector<int>> board;
    board.resize(5);
    for(int i=0;i<5;i++) board[i].resize(5);
    vector<int> moves; moves.resize(8);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin >> board[i][j];
        }
    }
    for(int i=0;i<8;i++) cin >> moves[i];
    cout << solution(board,moves);
}
