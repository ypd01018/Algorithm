#include<bits/stdc++.h>

using namespace std;

#define N 12
#define M 6
char arr[N][M],color_arr[5] = {'R','G','B','P','Y'};
bool check[N][M],sucess=1;
int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1},n,n_dot[M];
queue<pair<int,int>> q;
void make_star()
{
    int x,y;
    if(q.size()>3)
    {
        sucess = true;
        //n++;
        while(!q.empty())
        {
            tie(y,x) = q.front();
            arr[y][x] = '.';
            n_dot[x]--;
            q.pop();
        }
    }
    else
    {
        if(q.size())
            while(!q.empty()) q.pop();
    }
    
}
void DFS(char color, int y, int x)
{   
    if(arr[y][x] == color && !check[y][x])
    {
        q.push(make_pair(y,x));
        check[y][x] = 1;
        for(int i=0;i<4;i++)
        {
            if(x+dx[i]>-1 && x+dx[i] <M && y+dy[i]>-1 && y+dy[i]<N)
                DFS(color,y+dy[i],x+dx[i]);
        }
    }
}

void check_clear()
{
    for(int i = 0 ; i < N ;i++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            check[i][j]=0;
        }
    }
}

void go_down()
{
    for(int i = 0 ; i <M ; i++)
    {
        if(!n_dot[i]) continue;
        for(int j = N-1 ; j >0 ; j--)
        {
            if(arr[j][i] == '.' && arr[j-1][i] != '.')
            {
                char temp = arr[j][i];
                arr[j][i] = arr[j-1][i];
                arr[j-1][i] = temp;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M ;j++)
        {
            char tmp;
            cin >> tmp;
            arr[i][j]=tmp;
            if(arr[i][j]!='.') n_dot[j]++;
        }
    }


    while(sucess)
    {
        sucess = 0;
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < M ; j++)
            {
                for(int k = 0 ; k < 5; k++)
                {
                    if( arr[i][j] == color_arr[k] && !check[i][j])
                    {
                        DFS(color_arr[k],i,j); //특정 색 뿌요 모인거 체크하고
                        make_star();            // 4개이상 모인거면 터트리고 
                    } 
                }             // 이걸 모든 색에 하고
            }//모든 좌표에 하고

        }
        check_clear(); // 체크된거 해제해주고
        if(sucess) n++;
        for(int i = 0 ; i < 12 ; i ++) go_down(); // 별이 아래쪽이면 위로 올려주고


    }

    cout<<n;

}