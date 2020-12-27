#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int MOD = 10007;
long long N,K,mat[1004][1004];
void make()
{
    for(int i=0;i<1004;i++)
    {
        mat[i][0]=1;
    }
    mat[0][1] = 1;

    for(int i=1;i<1004;i++)
    {
        for(int j=1;j<i+2;j++)
        {   
            mat[i][j] = (mat[i-1][j] +mat[i-1][j-1])%MOD;
        }
    }
}

int main()
{
    make();

    cin >> N >> K;

    for(int i=0;i<50;i++)
    {
        for(int j=0;j<50;j++)
        {
            cout << mat[i][j] <<' ';
        }
        cout << endl;
    }
    


}