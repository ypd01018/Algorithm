#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
#define mp make_pair
using namespace std;

int N,M,K,mat[12][12],tree_cnt;
int input_add[12][12];
int dy[8]={-1,-1,0,1,1,1,0,-1}, dx[8]={0,1,1,1,0,-1,-1,-1};
struct tree_
{
    int x,y,z;
    bool life = true;
};
vector<tree_> tree_mat[12][12]; 
bool cmp(tree_ a, tree_ b)
{
    if(a.z < b.z) return true;
    else return false;

}
void spring_and_summer()
{
    int add_mat[12][12]={0};
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int tmp=1e9;
            sort(tree_mat[i][j].begin(),tree_mat[i][j].end(),cmp);
            for(int k=0;k<tree_mat[i][j].size();k++)
            {
                if(tree_mat[i][j][k].z<=mat[i][j]) 
                {
                    mat[i][j]-=tree_mat[i][j][k].z;
                    tree_mat[i][j][k].z++;
                }
                else
                {
                    tmp = k;
                    break;
                }
            }
            for(int k=tree_mat[i][j].size()-1;k>=tmp;k--)
            {
                tree_cnt--;
                add_mat[i][j]+=tree_mat[i][j][k].z/2;
                tree_mat[i][j].pop_back();
            }
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            mat[i][j]+=add_mat[i][j];
        }
    }
}
void make_tree(int x,int y)
{
    for(int n=0;n<8;n++)
    {
        int ny = y+dy[n], nx=x+dx[n];
        if(ny<1 || nx<1 || ny>N || nx>N) continue;
        tree_cnt++;
        tree_ new_tree;
        new_tree.y = ny, new_tree.x = nx; new_tree.z=1;
        tree_mat[nx][ny].push_back(new_tree);
    }
}
void fall_and_winter()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            for(int k=0;k<tree_mat[i][j].size();k++)
            {
                if(tree_mat[i][j][k].z%5==0) make_tree(i,j);
            }
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            mat[i][j]+=input_add[i][j];
        }
    }
}
int main()
{
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> input_add[i][j];
            mat[i][j]=5;
        }
    }
    for(int i=1;i<=M;i++)
    {
        tree_ new_tree;
        cin >> new_tree.x >> new_tree.y >> new_tree.z;
        tree_mat[new_tree.x][new_tree.y].push_back(new_tree);
        tree_cnt++;
    }
    for(int i=0;i<K;i++)
    {
        spring_and_summer();
        fall_and_winter();
    }
    cout << tree_cnt;
}