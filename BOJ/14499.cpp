#include<bits/stdc++.h>
#define y first
#define x second
#define east 1
#define west 2
#define north 3
#define south 4
using namespace std;
int N,M,k;
int mat[50][50],dice[7],bottom=6,dice_mat[4][3] = {{0,2,0},{4,1,3},{0,5,0},{0,6,0}};
int type;
pair<int,int> dice_co;
stack<int> stk;

bool check(int val)
{
    if( val < 0 ||  val > N-1) return false;
    return true;
}
bool check_y(int val)
{
    if( val < 0 ||  val > M-1) return false;
    return true;
}

bool dice_move(int cmd)
{
    int x = dice_co.x , y = dice_co.y;
    switch(cmd)
    {
        case east:
            y++;
            if(!check_y(y)) return false;
            dice_co.y = y;
            stk.push(dice_mat[3][1]);
            stk.push(dice_mat[1][0]);
            stk.push(dice_mat[1][1]);
            stk.push(dice_mat[1][2]);
            dice_mat[3][1]=stk.top(); stk.pop();
            dice_mat[1][2]=stk.top(); stk.pop();
            dice_mat[1][1]=stk.top(); stk.pop();
            dice_mat[1][0]=stk.top(); stk.pop();
            break;
        case west:
            y--;
            if(!check_y(y)) return false;
            dice_co.y=y;
            stk.push(dice_mat[3][1]);
            stk.push(dice_mat[1][0]);
            stk.push(dice_mat[1][1]);
            stk.push(dice_mat[1][2]);
            dice_mat[1][1]=stk.top(); stk.pop();
            dice_mat[1][0]=stk.top(); stk.pop();
            dice_mat[3][1]=stk.top(); stk.pop();
            dice_mat[1][2]=stk.top(); stk.pop();
            break;
        case north:
            x--;
            if(!check(x)) return false;
            dice_co.x=x;
            stk.push(dice_mat[0][1]);
            stk.push(dice_mat[1][1]);
            stk.push(dice_mat[2][1]);
            stk.push(dice_mat[3][1]);
            dice_mat[2][1]=stk.top(); stk.pop();
            dice_mat[1][1]=stk.top(); stk.pop();
            dice_mat[0][1]=stk.top(); stk.pop();
            dice_mat[3][1]=stk.top(); stk.pop();
            break;
        case south:
            x++;
            if(!check(x)) return false;
            dice_co.x=x;
            stk.push(dice_mat[0][1]);
            stk.push(dice_mat[1][1]);
            stk.push(dice_mat[2][1]);
            stk.push(dice_mat[3][1]);
            dice_mat[0][1]=stk.top(); stk.pop();
            dice_mat[3][1]=stk.top(); stk.pop();
            dice_mat[2][1]=stk.top(); stk.pop();
            dice_mat[1][1]=stk.top(); stk.pop();
            break;
    }
    

    dice_co.x = x;
    dice_co.y = y;
    bottom = dice_mat[3][1];
    
    return true;

}
void dice_num()
{
    if(mat[dice_co.x][dice_co.y])
    {
        dice[bottom] = mat[dice_co.x][dice_co.y];
        mat[dice_co.x][dice_co.y] = 0;        
    }
    else
    {
        mat[dice_co.x][dice_co.y] = dice[bottom];
    }
}

int main()
{   

    cin>>N>>M>>dice_co.x>>dice_co.y>>k;

    for(int i = 0 ; i < N ; i++)
    {
        for(int j=0;j<M;j++)
        {
            int input;
            cin >> input;
            mat[i][j] = input;
        }
    }    

    for(int i=0;i<k;i++)
    {
        int cmd;
        cin >> cmd;
        if(dice_move(cmd))
        {
            dice_num();
            cout << dice[dice_mat[1][1]]<<endl;
        }
    }


}