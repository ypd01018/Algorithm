#include<iostream>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<string>
#define endl "\n"
using namespace std;
int N,mat[22][22],check[22][22],dy[4]={-1,0,1,0},dx[4]={0,1,0,-1},mx=-1;
void find_max()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            mx = max(mat[i][j],mx);
        }
    }
}

int find_idx(int y, int x, int d)
{//0이 아닌 곳을 찾는 함수입니다.
    int ret;
    switch(d)
    {
        case(0):
            ret=y-1;
            for(int i=y-1;i>=0;i--)
            {
                ret = i;
                if(mat[i][x]) break;//자신의 위치부터 탐색하다가 0이 아닌곳이 발견되면 혹은 끝이면 더이상 못가므로 그만합니다.
            }
            return ret; //0이 아닌곳 혹은 더이상 못간곳의 위치가 반환됩니다.
        case(1):
            ret=x+1;
            for(int i=x+1;i<N;i++)
            {
                ret = i;
                if(mat[y][i]) break;
            }
            return ret;
        case(2):
            ret=y+1;
            for(int i=y+1;i<N;i++)
            {
                ret = i;
                if(mat[i][x]) break;
            }
            return ret;
        case(3):
            ret=x-1;
            for(int i=x-1;i>=0;i--)
            {
                ret = i;
                if(mat[y][i]) break;
            }
            return ret;
        default:
            cout << "wrong"<<endl;
            return -1;
    }
}
void lft()
{
    for(int i=0;i<N;i++)
    {
        for(int j=1;j<N;j++)
        {
            if(!mat[i][j]) continue;

            int idx=find_idx(i,j,3);//처음 0이 아닌곳을 찾습니다.
            if(mat[i][idx])//0이 아닌곳이 맞을 때
            {
                if(mat[i][j]==mat[i][idx]&&!check[i][idx]) //자신과 같고 해당 횟수에서 합쳐진 전적이 없는 타일이면 합쳐줍니다
                {
                    mat[i][j]=0; mat[i][idx] *=2; check[i][idx]=1; 
                }
                else//자신과 다르거나 합쳐진 전적이 있으면 해당 인덱스의 전 위치에 넣어줍니다.
                {
                    int tmp=mat[i][j];
                    mat[i][j]=0; mat[i][idx+1]=tmp;
                }
                
            }
            else // 0이면 해당 위치에 넣습니다.
            {
                int tmp=mat[i][j];
                mat[i][j]=0; mat[i][idx]=tmp;
            }
        }
    }
}

void rght()
{
    for(int i=0;i<N;i++)
    {
        for(int j=N-2;j>=0;j--)
        {
            if(!mat[i][j]) continue;

            int idx=find_idx(i,j,1);
            if(mat[i][idx])
            {
                if(mat[i][j]==mat[i][idx] && !check[i][idx])
                {
                    mat[i][j]=0; mat[i][idx] *=2; check[i][idx]=1; 
                }
                else
                {
                    int tmp=mat[i][j];
                    mat[i][j]=0; mat[i][idx-1]=tmp;
                }
            }
            else
            {
                int tmp=mat[i][j];
                mat[i][j]=0; mat[i][idx]=tmp;
            }
        }
    }
}
void go_up()
{
    for(int i=0;i<N;i++)
    {
        for(int j=1;j<N;j++)
        {
            if(!mat[j][i]) continue;

            int idx=find_idx(j,i,0);
            if(mat[idx][i])
            {
                if(mat[j][i]==mat[idx][i]&&!check[idx][i])
                {
                    mat[j][i]=0; mat[idx][i] *=2; check[idx][i]=1;
                }
                else
                {
                    int tmp=mat[j][i];
                    mat[j][i]=0; mat[idx+1][i]=tmp;
                }   
            }
            else
            {
                int tmp=mat[j][i];
                mat[j][i]=0; mat[idx][i]=tmp;
            }
        }
    }
}
void go_down()
{
    for(int i=0;i<N;i++)
    {
        for(int j=N-2;j>=0;j--)
        {
            if(!mat[j][i]) continue;

            int idx=find_idx(j,i,2);
            if(mat[idx][i])
            {
                if(mat[j][i]==mat[idx][i]&&!check[idx][i])
                {
                    mat[j][i]=0; mat[idx][i] *=2; check[idx][i]=1;
                }
                else
                {
                    int tmp=mat[j][i];
                    mat[j][i]=0; mat[idx-1][i]=tmp;
                } 
            }
            else
            {
                int tmp=mat[j][i];
                mat[j][i]=0; mat[idx][i]=tmp;
            }
        }
    }
}
void DFS(int cnt)
{
    if(cnt==5) //현재 몇번 이동했는지 횟수 5번이면 조건 만족으로 그만합니다.
    {
        find_max();//해당 타일중 가장 큰 수를 찾습니다.
        return;
    }
    int cpy[22][22];

    memcpy(cpy,mat,sizeof(mat));
    memset(check,0,sizeof(check));

    lft();//왼쪽으로 옮기고
    DFS(cnt+1);//다음 옮길 행동을 하러 재귀를 들어갑니다.
    memcpy(mat,cpy,sizeof(cpy)); memset(check,0,sizeof(check)); // 재귀를 갔다 왔으면 다시 원상복구 해놓습니다.
    //이를 모든 방향에 맞게 진행합니다.

    rght();
    DFS(cnt+1); 
    memcpy(mat,cpy,sizeof(cpy)); memset(check,0,sizeof(check));
    
    go_up();
    DFS(cnt+1); 
    memcpy(mat,cpy,sizeof(cpy)); memset(check,0,sizeof(check));
    
    go_down();
    DFS(cnt+1);
    memcpy(mat,cpy,sizeof(cpy)); memset(check,0,sizeof(check));

}
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> mat[i][j];
        }
    }
    DFS(0);
    cout << mx;
}