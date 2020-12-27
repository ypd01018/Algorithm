#include<iostream>
#define endl "\n"
using namespace std;

void sol();

int n;
bool mat[255][1000];

void sol();
int main()
{
    
    for(int i = 0 ; i< 10 ; i++)
    {
        cout << "#" << i+1 << " ";
        sol();
        cout << endl;
    }
}

void sol()
{
    int n,h,cnt = 0;
    cin >> n;
    for(int i = 0 ; i < n; i ++)
    {
        cin >> h;
        for(int j = 0 ; j < 255; j ++)
        {
            if(j < h) mat[j][i] = 1;
            else mat[j][i] = 0;
        }
    }

    for(int i=0;i<255;i++)
    {
        for(int j=2;j<n-2;j++)
        {
            if(mat[i][j] && !mat[i][j-2] && !mat[i][j-1] && !mat[i][j+1] && !mat[i][j+2]) cnt ++;
        }
    }

    cout << cnt ;
}