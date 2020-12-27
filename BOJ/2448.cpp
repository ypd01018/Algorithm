#include<iostream>
#define endl "\n"

using namespace std;

char mat[7000][7000];

void draw(int n, int x, int y);
int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2*n-1;j++)
        {
            mat[i][j]=' ';
        }
    }


    draw(n/2, (n*2-1)/2, 0);
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2*n-1;j++)
        {
            cout<<mat[i][j];
        }
    if(i!= n-1) cout << endl;
    }

}
void draw(int n, int x, int y)
{
    if(n == 1)
    {

        mat[y][x]='*';

        mat[y+1][x-1]='*';
        mat[y+1][x+1]='*';
        
        mat[y+2][x-2]='*';
        mat[y+2][x-1]='*';
        mat[y+2][x]='*';
        mat[y+2][x+1]='*';
        mat[y+2][x+2]='*';
        
        return ;
    }
    draw(n/2, x, y);
    draw(n/2, x+n, y+n);
    draw(n/2, x-n, y+n);

}