    #include<bits/stdc++.h>
    #define endl "\n"
    #define obj first
    #define dis second
    using namespace std;
    int T,w,h,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    pair<char,pair<int,int>> mat[1002][1002];
    bool issued[1002][1002];
    queue<pair<int,int>> people,fire;
    void input()
    {
        cin >> w >> h;
        while(!fire.empty()) fire.pop();
        while(!people.empty()) people.pop();

        for(int i=0;i<h;i++)
        {
            string tmp;
            cin >> tmp;
            for(int j=0;j<w;j++) issued[i][j]=0;
            for(int j=0;j<w;j++)
            {
                mat[i][j].obj=tmp[j];
                mat[i][j].second.first = mat[i][j].second.second = 0; 
                if(tmp[j]=='@')
                {
                    people.push({i,j});
                    issued[i][j]=1;
                }if(tmp[j]=='*') fire.push({i,j});
            }
        }
    }
    void sol()
    {
        int lecord_fire=0,lecord_people=0;
        bool flag=false;
        while(!people.empty() || !fire.empty())
        {
            int y,x;
            while(!fire.empty())
            {
                tie(y,x) = fire.front();
                if(mat[y][x].dis.first!=lecord_fire) 
                {
                    lecord_fire++;
                    break;
                }
                
                fire.pop();

                for(int i=0;i<4;i++)
                {
                    int ny = y+dy[i],nx = x +dx[i];
                    if(ny >= 0 && nx >=0 && ny < h && nx < w && !issued[ny][nx] && (mat[ny][nx].obj=='.'||mat[ny][nx].obj=='@'))
                    {
                        mat[ny][nx].obj='*'; mat[ny][nx].dis.first=mat[y][x].dis.first+1;
                        fire.push({ny,nx});
                    }
                }
                
            }
            while(!people.empty())
            {
                tie(y,x) = people.front();
                if(y == 0 || x == 0 || y == h-1 || x == w-1)
                {
                    flag = true;
                    break;
                }
                if(mat[y][x].dis.second!=lecord_people) 
                {
                    lecord_people++;
                    break;
                }
                people.pop();
                for(int i=0;i<4;i++)
                {
                    int ny = y+dy[i],nx = x +dx[i];
                    if(ny >= 0 && nx >=0 && ny < h && nx < w && !issued[ny][nx] && mat[ny][nx].obj=='.')
                    {
                        mat[ny][nx].obj='@'; mat[ny][nx].dis.second=mat[y][x].dis.second+1;
                        people.push({ny,nx});
                    }
                }        
            }
            if(flag)
            {
                cout << mat[y][x].dis.second+1<<endl;
                break;
            }
        }
        if(!flag) cout <<"IMPOSSIBLE"<<endl;

    }
    int main()
    {
        cin >> T;
        for(int i=0;i<T;i++)
        {
            input();
            sol();
        }
    }