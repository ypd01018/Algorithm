#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int R,C,M,dy[5]={0,-1,1,0,0},dx[5]={0,0,0,1,-1},ans;
vector<int> v[101];
struct shark
{
    int r,c,s,d,z;
    bool life=true;
};
shark sha[100'010];
void reverse_check(int i)
{
    if(sha[i].d==1 && sha[i].r==1) 
    {
        sha[i].d=2;
        return;
    }
    if(sha[i].d==2 && sha[i].r==R)
    {
        sha[i].d=1;
        return;
    }
    if(sha[i].d==3 && sha[i].c==C)
    {
        sha[i].d=4;
        return;
    }
    if(sha[i].d==4 && sha[i].c==1)
    {
        sha[i].d=3;
        return;
    }
}

void shark_move()
{
    for(int i=0;i<M;i++)
    {
        if(sha[i].life)
        {
            int s;
            if(sha[i].d==1 || sha[i].d == 2) 
            {
                s = sha[i].s % (R*2-2);
                for(int j=0;j<s;j++)
                {
                    reverse_check(i);
                    sha[i].r += dy[sha[i].d];
                }

            }
            else
            {
                s=sha[i].s% (C*2-2);
                for(int j=0;j<s;j++)
                {
                    reverse_check(i);
                    sha[i].c += dx[sha[i].d]; 
                }
 
            }
        }
    }
}
void vector_init()
{
    //eating check
    for(int i=0;i<M;i++)
    {
        if(sha[i].life)
        for(int j=i+1;j<M;j++)
        {
            if(sha[j].life && sha[i].r == sha[j].r && sha[i].c == sha[j].c)
            {
                if(sha[i].z > sha[j].z)
                {
                    sha[j].life = false;
                }
                else
                {
                    sha[i].life = false;
                }
                
            }
        }
    }

    for(int i=0;i<=C;i++) v[i].clear();
    
    for(int i=0;i<M;i++)
    {
        if(sha[i].life)
        v[sha[i].c].push_back(i);
    }
}
void print_test()
{
    for(int i=0;i<M;i++)
    {
        auto target = sha[i];
        cout << i << '-' << " life:"<<target.life<<" r:" <<target.r << " c:" << target.c << " d:" << target.d << " s:" << target.s << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> M;
    for(int i=0;i<M;i++)
    {
        int r,c,s,d,z;
        cin >> sha[i].r >> sha[i].c >> sha[i].s >> sha[i].d >> sha[i].z;
        v[sha[i].c].push_back(i);
    }

    for(int i=1;i<=C;i++)
    {
        int target,mn=INT_MAX;bool flag=false;
        for(int j=0;j<v[i].size();j++)
        {
            if(sha[v[i][j]].life && mn > sha[v[i][j]].r)
            {
                flag = true;
                target = v[i][j];
                mn = sha[v[i][j]].r;
//                cout << "target:" << target <<"mn:" << mn << endl;
            }
        }
//        cout << "i:" << i << " target:" << target << endl;
        if(flag)
        {
            sha[target].life=false;
            ans += sha[target].z;
        }
//        print_test();
        shark_move();
        vector_init();
//        cout << ans << endl;
        
    }


    cout << ans;
    

}