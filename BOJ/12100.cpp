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
void print_test(string a)
{
    cout <<"--------------"<<a<<"--------------"<< endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
    
}
int find_idx(int y, int x, int d)
{
    int ret;
    switch(d)
    {
        case(0):
            ret=y-1;
            for(int i=y-1;i>=0;i--)
            {
                ret = i;
                if(mat[i][x]) break;
            }
            return ret;
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

            int idx=find_idx(i,j,3);
            if(mat[i][idx])
            {
                if(mat[i][j]==mat[i][idx]&&!check[i][idx])
                {
                    mat[i][j]=0; mat[i][idx] *=2; check[i][idx]=1; 
                }
                else
                {
                    int tmp=mat[i][j];
                    mat[i][j]=0; mat[i][idx+1]=tmp;
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

            int idx=find_idx(j,i,0); //cout <<"idx:"<< idx;
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
    if(cnt==5) 
    {
        find_max();
        return;
    }
    int cpy[22][22];

    memcpy(cpy,mat,sizeof(mat));
    memset(check,0,sizeof(check));

    lft();// print_test("lft");
    DFS(cnt+1);
    memcpy(mat,cpy,sizeof(cpy)); memset(check,0,sizeof(check));
    
    rght();// print_test("rght");
    DFS(cnt+1); 
    memcpy(mat,cpy,sizeof(cpy)); memset(check,0,sizeof(check));
    
    go_up(); //print_test("up");
    DFS(cnt+1); 
    memcpy(mat,cpy,sizeof(cpy)); memset(check,0,sizeof(check));
    
    go_down(); //print_test("down");
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