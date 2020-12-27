#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int mat[10][10],visited[10][10],one_cnt,paper_cnt,mn=INT_MAX;
int color_paper[6]={5,5,5,5,5,5};

bool check(int a,int y, int x)
{
    a--;
    for(int i=y;i<=y+a;i++)
    {
        for(int j=x;j<=x+a;j++)
        {
            if(i>=10 || j >=10) return false;
            if(!mat[i][j]) return false;
            
            mat[i][j]=0;
        }
    }
    return true;
}

void go(int a)
{
    if(one_cnt==0)
    {
        mn = min(mn,paper_cnt);
        return;
    }

    if(a==100)
    {
        return;
    }
    
    if(mat[a/10][a%10])
    {
        int cpy[10][10];
        memcpy(cpy,mat,sizeof(mat));
        for(int i=1;i<=5;i++)
        {
            if(check(i,a/10,a%10)) 
            {
                if(color_paper[i]>0)
                {
                    paper_cnt++;
                    color_paper[i]--;
                    one_cnt -= i*i;
                
                    go(a+1);

                    paper_cnt--;
                    color_paper[i]++;
                    one_cnt += i*i;
                }

            }
            memcpy(mat,cpy,sizeof(cpy));
        }
    }
    else go(a+1);
}

int main()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]) one_cnt++;
        }
    }

    go(0);

    if(mn==INT_MAX) cout <<-1;
    else cout << mn;

}