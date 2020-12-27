#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,dy[4]={-1,0,1,0}, dx[4] = {0,1,0,-1};
int mat[51][51];
bool visited[151];
vector<pair<int,int>> chicken,person;
int chic_sel[150];
int min_dis[150][1500],ans_min=999999999;

void distance()
{
    for(int i=0;i<chicken.size();i++)
    {
        int chic_y,chic_x;
        tie(chic_y,chic_x) = chicken[i];
        for(int j=0;j<person.size();j++)
        {
            int per_y,per_x;
            tie(per_y,per_x)=person[j]; 
            min_dis[i][j]= abs(chic_y-per_y) + abs(chic_x-per_x);
        }
    }
}
//int n_chic;

void DFS(int a,int n_chic)
{

    if(a>chicken.size()) return;

    if(n_chic == M)
    {
        int tot=0;
        for(int i=0;i<person.size();i++)
        {
            int mn = 999999999;
            for(int j=0;j<n_chic;j++)
            {
                mn = min(mn,min_dis[chic_sel[j]][i]);
            }
            tot+=mn;
        }
        ans_min = min(tot,ans_min);
        return;
    }
        chic_sel[n_chic]=a;
        DFS(a+1,n_chic+1);
        DFS(a+1,n_chic);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]==1) person.push_back({i,j});
            if(mat[i][j]==2) chicken.push_back({i,j});
        }
    }
    distance();
    DFS(0,0);
    cout << ans_min;


}