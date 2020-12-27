#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,K,A[12][12],mat_energy[12][12],dy[8]={-1,-1,0,1,1,1,0,-1},dx[8]={0,1,1,1,0,-1,-1,-1},total_tree,five[12][12];
vector<int> mat[12][12];
int n_tree[12][12];
void spring_summer()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int n = n_tree[i][j];
            sort(mat[i][j].begin(),mat[i][j].end());
            if(n)
            {   
                int plu=0;
                vector<int>::iterator iter=mat[i][j].begin();
                while(iter != mat[i][j].end())
                {
                    if(mat_energy[i][j]>=(*iter))
                    {
                        mat_energy[i][j] -= (*iter);
                        (*iter)++;
                        iter++;
                    }
                    else
                    {
                        plu += (*iter)/2;
                        iter=mat[i][j].erase(iter);
                        n_tree[i][j]--; total_tree--;
                    }
                 }
                 
                mat_energy[i][j] += plu;
            }
        }
    }
}
void make_tree(int y, int x)
{
    for(int i=0;i<8;i++)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if(ny >=0 && nx >=0 && ny <N && nx < N)
        {
            mat[ny][nx].push_back(1);
            n_tree[ny][nx]++; total_tree++;
        }
    }
}
void fall_winter()
{
    int cpy[12][12];
    memcpy(cpy,n_tree,sizeof(n_tree));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int n = cpy[i][j];
            vector<int>::iterator iter;
            for(iter = mat[i][j].begin();iter!=mat[i][j].end();iter++)
            {
                if(*iter > 0 && (*iter)%5 == 0 )
                {
                    make_tree(i,j);
                }
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            mat_energy[i][j] += A[i][j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M >> K;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> A[i][j];
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            mat_energy[i][j]=5;
        }
    }
    for(int i=0;i<M;i++)
    {
        int x,y,z;
        cin >> y >> x >> z;
        mat[y-1][x-1].push_back(z);
        n_tree[y-1][x-1]++;
        total_tree++;
    }
    for(int i=0;i<K;i++)
    {
        spring_summer();
        fall_winter();
        if(!total_tree) break;
    }
    cout << total_tree ;
}