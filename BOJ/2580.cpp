#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int arr[10][10];
vector<pair<int,int>> v;
bool check(int y,int x)
{
    int _y[10]={0,},_x[10]={0,},mini[10]={0,};
    //cout << "_y" << endl;
    for(int i=0;i<9;i++)
    {
        //cout << "i:" << i <<' ';
        if(!arr[y][i]) continue;
        if(_y[arr[y][i]]) return false;
        else _y[arr[y][i]]++;
    }
    //cout << endl;
    //cout << "_x" << endl;
    for(int i=0;i<9;i++)
    {
        //cout <<"i:" << i <<' ';
        if(!arr[i][x]) continue;
        if(_x[arr[i][x]]) return false;
        else _x[arr[i][x]]++;
    }
    //cout << endl;
    //cout <<"mini" << endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(!arr[(y/3)*3+i][(x/3)*3+j]) continue;

            if(mini[arr[(y/3)*3+i][(x/3)*3+j]]) return false;
            else mini[arr[(y/3)*3+i][(x/3)*3+j]]++;
        }
    }
    
    return true;
}
void DFS(int a)
{
    //cout << "a:" << a << endl;
    if(a==v.size())
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }
        exit(0);
        return;
    }

    int y,x;
    //for(int i=a;i<v.size();i++)
    {
        tie(y,x)=v[a];
        for(int j=1;j<10;j++)
        {
            //cout <<endl<< "v[" << j<<"]:" << endl;
            arr[y][x] = j;
            if(check(y,x))
            {
                DFS(a+1);
            }
            arr[y][x]=0;
        }
    }

}
int main()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]==0) v.push_back({i,j});
        }
    }

    DFS(0);
}
