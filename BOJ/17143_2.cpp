#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int R,C,M,dy[5]={0,-1,1,0,0},dx[5]={0,0,0,1,-1},ans,mat[102][102];
struct shark
{
    int r,c,s,d,z;
    bool life=true;
};
shark sha[100'010];
void shark_move()
{
    memset(mat,0,sizeof(mat));
    for(int i=1;i<=M;i++)
    {
        if(sha[i].life)
        {
            int s;
            if(sha[i].d==1 || sha[i].d == 2) s = sha[i].s % (R*2-2);
            else s=sha[i].s % (C*2-2); 
            

            for(int j=0;j<s;j++)
            {
                if(sha[i].d==1 && sha[i].r==1) 
                {
                    sha[i].d=2;
                }
                else if(sha[i].d==2 && sha[i].r==R)
                {
                    sha[i].d=1;
                }
                else if(sha[i].d==3 && sha[i].c==C)
                {
                    sha[i].d=4;
                }
                else if(sha[i].d==4 && sha[i].c==1)
                {
                    sha[i].d=3;
                }
                sha[i].r += dy[sha[i].d];
                sha[i].c += dx[sha[i].d]; 
            }
            if(mat[sha[i].r][sha[i].c]==0)
            {
                mat[sha[i].r][sha[i].c]=i;
            }
            else
            {
                if(sha[mat[sha[i].r][sha[i].c]].z > sha[i].z ) sha[i].life=0;
                else
                {
                    sha[mat[sha[i].r][sha[i].c]].life =0;
                    mat[sha[i].r][sha[i].c]=i;
                }
                
            }
            
        }
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> M;
    if(M==0)
    {
        cout << 0;
        exit(0);
    }
    for(int i=1;i<=M;i++)
    {
        int r,c,s,d,z;
        cin >> sha[i].r >> sha[i].c >> sha[i].s >> sha[i].d >> sha[i].z;
        mat[sha[i].r][sha[i].c]=i;
    }

    for(int i=1;i<=C;i++)
    {
        int target,mn=INT_MAX;bool flag=false;
        for(int j=1;j<=R;j++)
        {
            if(mat[j][i]==0) continue;
            if(sha[mat[j][i]].life && mn > sha[mat[j][i]].r)
            {
                flag = true;
                target = mat[j][i];
                mn = sha[target].r;
            }
        }
        if(flag)
        {
            sha[target].life=false;
            ans += sha[target].z;
        }
        shark_move();
    }
    cout << ans;
}