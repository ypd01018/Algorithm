#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define MAX 30
int T;
long long N,K,mat[MAX][MAX];
void make()
{
    for(int i=0;i<MAX;i++)
    {
        mat[i][0]=1;
    }
    mat[0][1] = 1;

    for(int i=1;i<MAX;i++)
    {
        for(int j=1;j<i+2;j++)
        {   
            mat[i][j] = (mat[i-1][j] +mat[i-1][j-1]);
        }
    }
}

int main()
{
    
    make();
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> N >> K;
        cout << mat[max(N,K)-1][min(N,K)] << endl;
    }


}