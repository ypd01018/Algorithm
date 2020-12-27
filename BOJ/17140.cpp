#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int R,C,K,mat[102][102];
int r_len=3,c_len=3;
pair<int,int> arr[120];

bool comp(pair<int,int> a, pair<int,int> b)
{
    if(a.second < b.second) return 1;
    else if(a.second > b.second) return 0;
    else
    {
        if(a.first < b.first) return 1;
        else return 0;
    }
}

void r_action(int r)
{
    memset(arr,0,sizeof(arr));
    for(int i=0;i<c_len;i++)
    {
        arr[mat[r][i]].second++;
        arr[mat[r][i]].first=mat[r][i];
    }
    for(int i=0;i<c_len;i++)
    {
        mat[r][i]=0;
    }
    sort(arr+1,arr+101,comp);

    int idx=0;
    for(int i=1;i<=100;i++)
    {
        if(arr[i].first)
        {
            mat[r][idx++]=arr[i].first;
            mat[r][idx++]=arr[i].second;
        }
    }
    c_len = max(c_len,idx);
}
void c_action(int c)
{
    memset(arr,0,sizeof(arr));
    for(int i=0;i<r_len;i++)
    {
        arr[mat[i][c]].second++;
        arr[mat[i][c]].first=mat[i][c];
    }
    for(int i=0;i<r_len;i++)
    {
        mat[i][c]=0;
    }
        
    sort(arr+1,arr+101,comp);

    int idx=0;
    for(int i=1;i<=100;i++)
    {
        if(arr[i].first)
        {
            mat[idx++][c]=arr[i].first;
            mat[idx++][c]=arr[i].second;
        }
    }
    r_len = max(r_len,idx);
}
void print_test()
{
    cout << endl;
    for(int i=0;i<r_len;i++)
    {
        for(int j=0;j<c_len;j++)
        {
            cout << mat[i][j] << ' '; 
        }
        cout << endl;
    }
}
int main()
{
    cin >> R >> C >> K;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> mat[i][j];
        }
    }

    int turn=0;

    while(mat[R-1][C-1]!=K)
    {
        if(r_len >= c_len)
        {
            int len = r_len;
            for(int i=0;i<len;i++)
            {
                r_action(i);
            }
        }
        else
        {
            int len = c_len;
            for(int i=0;i<len;i++)
            {
                c_action(i);
            }
        }
        //print_test();
        turn++;
        if(turn >100) 
        {
            cout << -1;
            exit(0);
        }
    }
    cout << turn;
}


// 8시 33분 해결완료, 걸린시간 : 43분