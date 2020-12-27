#include<bits/stdc++.h>
#define endl "\n"
#define y first
#define x second
using namespace std;
int n,cnt,mx[2];
bool diag[2][20];
vector<pair<int,int>> v[2];

void chess(int bw, int a)
{
    for(int i = a ; i < v[bw].size() ; i++)
    {
        if(!diag[0][ v[bw][i].x - v[bw][i].y + n -1] && !diag[1][v[bw][i].x + v[bw][i].y])
        {
            diag[0][ v[bw][i].x - v[bw][i].y + n -1]= diag[1][v[bw][i].x + v[bw][i].y] =1;
            cnt++;
            mx[bw] = max(mx[bw],cnt);

            chess(bw,i);

            cnt--;
            diag[0][ v[bw][i].x - v[bw][i].y + n -1]= diag[1][v[bw][i].x + v[bw][i].y] =0;
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            int tmp;
            cin >> tmp;
            if(tmp)
            {
                v[(i+j)%2].push_back(make_pair(i,j));
            }
        }
    }

    chess(0,0);
    cnt=0;
    chess(1,0);
    
    cout << mx[0] + mx[1];

}