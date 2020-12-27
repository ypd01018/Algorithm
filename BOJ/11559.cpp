#include<bits/stdc++.h>

using namespace std;
char arr[12][6];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void BFS(char target,int x, int y)
{
    for(int i = 0 ; i < 12;i++)
    {
        for(int j = 0 ; j < 6 ; j++)
        {
            if(arr[i][j] == target)
            {
                arr[i][j]='*';
                for(int k=0;k<4;k++)
                {
                    if( j+dx[k] > -1 && j+dx[k] <6 && i+dy[k] > -1 && i+dy[k] < 12)
                        BFS(target,j+dx[k],i+dy[k]);

                }
            }
        }
    }
}
int main()
{
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<6;j++)
        {
            char tmp;
            cin >>tmp;
            arr[i][j]=tmp;
        }
    }
    cout <<"-------------------------------";
    BFS('R',0,0);

    for(int i=0;i<12;i++)
    {
        for(int j=0;j<6;j++)
        {
            cout << arr[i][j];
        }
        cout<<endl;
    }

}