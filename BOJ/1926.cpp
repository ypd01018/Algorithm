#include<iostream>
#define endl "\n"
#include<queue>
using namespace std;
int x,y,pic_count=0,best=0,temp=0;
pair<int,int> ary[501][501];
queue<pair<int,int>> q;
void bfs();
int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    cin >> y;
    cin >> x;
    for(int i=0; i < y; i++ )
    {
        for(int j=0;j<x;j++)
        {
            cin >> ary[i][j].first;
            ary[i][j].second=0;
        }
    } 

    for(int i=0; i < y; i++ )
    {
        for(int j=0;j<x;j++)
        {
            if(ary[i][j].first==1 && ary[i][j].second == 0)
            {
                pic_count ++ ;
                q.push(make_pair(j,i));
                bfs();
            }
            
        }
    } 


    cout << pic_count<<endl<<best;

    
}

void bfs()
{
    temp=0;
    int temp_x,temp_y;
    while(q.empty() != 1)
    {   
        temp ++ ;
        temp_x=q.front().first;
        temp_y=q.front().second;
        ary[temp_y][temp_x].second = 1;
        q.pop();

        if(temp_x>0 && ary[temp_y][temp_x-1].first == 1 && ary[temp_y][temp_x-1].second == 0)
        { 
            ary[temp_y][temp_x-1].second=1;
            q.push(make_pair(temp_x-1,temp_y));
        }
        if(temp_y>0 && ary[temp_y-1][temp_x].first == 1 && ary[temp_y-1][temp_x].second == 0) 
        {
            ary[temp_y-1][temp_x].second=1;
            q.push(make_pair(temp_x,temp_y-1));
        }
        if(temp_x<x-1 && ary[temp_y][temp_x+1].first == 1 && ary[temp_y][temp_x+1].second == 0) 
        {
            ary[temp_y][temp_x+1].second=1;
            q.push(make_pair(temp_x+1,temp_y));
        }
        if(temp_y<y-1 && ary[temp_y+1][temp_x].first == 1 && ary[temp_y+1][temp_x].second == 0) 
        {
            ary[temp_y+1][temp_x].second=1;
            q.push(make_pair(temp_x,temp_y+1));
        }
//.       cout << temp << "  temp_x:"<<temp_x << ", temp_y:"<<temp_y<<endl;

    }
//    cout << endl;
    if(temp > best) best = temp;
}