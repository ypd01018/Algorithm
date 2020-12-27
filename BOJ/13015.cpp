#include<bits/stdc++.h>
#define endl "\n"
#define N 2*n-1
#define M 4*n-3
using namespace std;
char mat[500][500];

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<2*n-1;i++)
    {
        for(int j=0;j<4*n-3;j++)
        {
            mat[i][j]=' ';
        }
    }

    for(int i=0;i<n;i++)
    {
        mat[0][i]='*';
        mat[0][3*n-3+i]='*';
        mat[2*n-2][i]='*';
        mat[2*n-2][3*n-3+i]='*';
    }

    for(int i=1;i<n;i++)
    {
        mat[i][i]='*';
        mat[i][i+(n-1)]='*';

        mat[i][4*n-4-i]='*';
        mat[i][4*n-4-i-(n-1)]='*';

        mat[N-1-i][i]='*';
        mat[N-1-i][i+(n-1)]='*';

        mat[N-1-i][4*n-4-i]='*';
        mat[N-1-i][4*n-4-i-(n-1)]='*';
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4*n-3-i;j++)
        {
            cout << mat[i][j];             
        }
        cout << endl;
    }

    for(int i=n;i<2*n-1;i++)
    {
        for(int j=0;j<M-(n)+(i-n)+2;j++)
        {
            cout << mat[i][j];             
        }
        cout << endl;
    }
}