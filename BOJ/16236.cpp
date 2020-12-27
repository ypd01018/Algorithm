#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,mat[22][22],turn,dis[22][22],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
vector<pair<int,int>> v;
vector<pair<int,int>> v_new;


struct shark
{
    int eat=0;
    int y,x;
    int size = 2;
};
shark sha;
void print_test()
{
    cout << endl;
    cout <<"turn:"<< turn <<"  [" <<sha.y <<','<<sha.x <<']'<< "   size:" <<sha.size<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
}
void print_BFS()
{
    cout <<"--------------------DIS------------------------"<< endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << dis[i][j] << ' ';
        }
        cout << endl;
    }
    cout <<"--------------------DIS------------------------"<< endl;
}
void BFS()
{
    memset(dis,0,sizeof(dis));
    bool check[22][22];
    memset(check,0,sizeof(check));
    queue<pair<pair<int,int>,int>> q;
    q.push({{sha.y,sha.x},0});
    check[sha.y][sha.x]=1;

    while(!q.empty())
    {
        pair<int,int> yx = q.front().first;int distance = q.front().second; q.pop();
        dis[yx.first][yx.second] = distance;
        for(int i=0;i<4;i++)
        {
            int ny = yx.first+dy[i],nx=yx.second+dx[i];

            if(ny>=0 && nx>=0 && ny<N && nx<N && !check[ny][nx] && mat[ny][nx]<=sha.size)
            {
                q.push({{ny,nx},distance+1});
                check[ny][nx]=1;
            }
        }
    }

    //print_BFS();
}
void sha_eat()
{
    sha.eat++;
    if(sha.eat == sha.size) 
    {
        sha.eat=0;
        sha.size++;
    }
}
void search_high()
{
    int mn = INT_MAX;
    
    for(int i=0;i<v.size();i++)
    {
        if(mn>v[i].first)
        {
            v_new.clear();
            v_new.push_back({v[i].first,v[i].second});
            mn = v[i].first;
        }
        else if(mn==v[i].first)
        {
            v_new.push_back({v[i].first,v[i].second});
        }
    }
    if(v_new.size()==1)
    {
        sha.y = v_new[0].first; sha.x=v_new[0].second;
        sha_eat();
        turn += dis[v_new[0].first][v_new[0].second];
        mat[v_new[0].first][v_new[0].second]=0;
    }
    else
    {
        int fish_y,fish_x;
        mn=INT_MAX;
        for(int i=0;i<v_new.size();i++)
        {
            if(mn>v_new[i].second)
            {
                fish_y=v_new[i].first; fish_x=v_new[i].second;
                mn=v_new[i].second;
            }
        }
        sha.y = fish_y; sha.x=fish_x;
        sha_eat();
        turn += dis[fish_y][fish_x];
        mat[fish_y][fish_x]=0;
    }
    

}
void search_short()
{
    int mn = INT_MAX,cnt=0,tar_y,tar_x;
    for(int i=0;i<v.size();i++)
    {
        int fish_y=v[i].first,fish_x=v[i].second;
        if(dis[fish_y][fish_x]<mn)
        {
            cnt=0;
            mn=dis[fish_y][fish_x];
            tar_y=fish_y; tar_x=fish_x;
        }
        else if(dis[fish_y][fish_x]==mn)
        {
            cnt++;
        }
    }

    if(cnt==0)
    {
        sha.y=tar_y; sha.x=tar_x;
        sha_eat();
        turn += dis[tar_y][tar_x];
        mat[tar_y][tar_x]=0;
    }
    else
    {
        vector<pair<int,int>>::iterator iter=v.begin();
        while(iter!=v.end())
        {
            int y_ = (*iter).first, x_=(*iter).second;
            if(dis[y_][x_]>mn) iter=v.erase(iter); 
            else iter++;
        }
        search_high();
    }
    
}
bool search_fish()
{
    v.clear();

    int mn = INT_MAX;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(mat[i][j]>=1 && mat[i][j]<sha.size)
            {
                if(mat[i][j]<mn)
                {
                    v.clear();
                    v.push_back({i,j});
                    mn=mat[i][j];
                }
                else if(mat[i][j]==mn)
                {
                    v.push_back({i,j});
                }
            }
        }
    }
    cout <<"check:"<< v.size()<<endl;
    if(v.size()==0) return false;
    else if(v.size()==1)
    {
        sha.y = v[0].first; sha.x = v[0].second;
        sha_eat();
        turn += dis[v[0].first][v[0].second];
        mat[v[0].first][v[0].second]=0;
    }
    else
    {
        vector<pair<int,int>>::iterator iter=v.begin();
        while(iter!=v.end())
        {
            int y_ = (*iter).first, x_=(*iter).second;
            if(mat[y_][x_]>mn) iter=v.erase(iter); 
            else iter++;
        }
        search_short();
    }
    return true; 
}
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]==9)
            {
                sha.y=i;sha.x=j;
                mat[i][j]=0;
            }
        }
    }
    
    while(1)
    {
        BFS();
        if(!search_fish()) break;
        print_test();
    }
    cout << turn;


}