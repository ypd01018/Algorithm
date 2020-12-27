#include<bits/stdc++.h>

using namespace std;
int M,N,mat[1002][1002];
queue<pair<int,int>> q;
int main()
{
    
    cin >> M >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int tmp;
            cin >> tmp;
            mat[i][j]=tmp;
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(mat[i][j]) q.push({i,j}); 
        }
    }
    
    




}