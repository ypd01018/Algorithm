#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,B,mat[505][505],mn=1e9,mx=-1,check[300],mn_block=1e9,mx_block;
int go(int n)
{
    int block = B;
    int sec = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(mat[i][j]>n)
            {
                block += mat[i][j]-n;
                sec+= 2*(mat[i][j]-n);
            }
            else if(mat[i][j]<n)
            {
                block -= n-mat[i][j];
                sec += n-mat[i][j];
            }
        }
    }
    if(block<0) return 1e9;
    return sec;
}
int main()
{
    cin >> N >> M >> B;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >>  mat[i][j];
            mn_block = min(mn_block,mat[i][j]);
            mx_block = max(mx_block,mat[i][j]);
        }
    }
    for(int i=mn_block;i<=mx_block;i++)
    {
        int val;
        val = go(i);
        if(val<=mn)
        {
            mn = val;
            mx = i; 
        }
    }
    cout << mn <<' '<< mx;
}