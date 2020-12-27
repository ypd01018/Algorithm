    #include<bits/stdc++.h>
    #define endl "\n"
    #define val first
    #define turn second
    using namespace std;
    int L,R,C,dz[6]={1,-1,0,0,0,0},dy[6]={0,0,1,0,-1,0},dx[6]={0,0,0,1,0,-1},tz,ty,tx;
    pair<char,int> mat[33][33][33];
    bool visited[33][33][33];
    queue<pair<int,pair<int,int>>> q;
    void input()
    {
        for(int i=0;i<L;i++)
        {
            for(int j=0;j<R;j++)
            {
                string tmp;
                cin >> tmp;
                for(int k=0;k<C;k++)
                {
                    mat[i][j][k].val = tmp[k];
                    if(tmp[k]=='S') 
                    {
                        mat[i][j][k].turn =0;
                        q.push({i,{j,k}});
                    }
                    if(tmp[k]=='E')
                    {
                        tz=i; ty = j; tx=k;
                    }
                }
            }
        }
    }
    void BFS()
    {
        while(!q.empty())
        {
            int z=q.front().first ,y,x; tie(y,x) = q.front().second; q.pop();
            for(int i=0;i<6;i++)
            {
                int nz = z+dz[i], ny = y+dy[i], nx = x+dx[i];
                if(nz>=0 && ny>=0 && nx>=0 && nz<L && ny<R && nx<C && (mat[nz][ny][nx].val=='.' ||mat[nz][ny][nx].val=='E' ) && !visited[nz][ny][nx])
                {
                    visited[nz][ny][nx]=1;
                    mat[nz][ny][nx].turn = mat[z][y][x].turn+1;  
                    q.push({nz,{ny,nx}});
                }
            } 
        }
    }
    int main()
    {
        ios::sync_with_stdio(1);
        cin.tie(0);
        while(1)
        {
            cin >> L >> R >> C;
            if(!L && !R && !C) break;

            input();
            BFS();

            if(mat[tz][ty][tx].turn==0) cout << "Trapped!" << endl;
            else cout << "Escaped in "<< mat[tz][ty][tx].turn <<" minute(s)." << endl;

            memset(visited,0,sizeof(visited));
        }
    }