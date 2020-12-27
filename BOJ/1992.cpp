#include<iostream>
#define endl "\n"
#include<queue>
using namespace std;

int mat[128][128];
void comp(int n, int x, int y);
queue<char> q;
int main()
{
    int n;
    cin >> n;
    for(int i=0 ; i< n ; i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%1d", &mat[i][j]);
        }
    }

    comp(n,0,0);


    while(!q.empty())
    {
        cout<<q.front();
        q.pop();
    }

}

void comp(int n, int x, int y)
{
    int first;
    bool flag = true;
    first = mat[y][x];
    for(int i = y ; i < y+n ; i ++)
    {
        for(int j = x ; j < x+n ; j ++)
        {
            if(first != mat[i][j]) flag = false;
        }
    }

    if(flag == true)
    {

        if(mat[y][x] == 0)
            q.push('0');
        else q.push('1');
        return ;
    }
    q.push('(');
    comp(n/2, x, y);
    comp(n/2 ,x+n/2, y);
    comp(n/2, x, y+n/2);
    comp(n/2, x+n/2 , y+n/2);
    q.push(')');

}