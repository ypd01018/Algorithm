#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
unordered_map<string,int> um;
double percent[5][5][3];
int score[5],plus_score[3][2]={{3,0},{1,1},{0,3}};
void DFS(int a,int b,double val)
{
    int score_cache[5],nxt_a=a,nxt_b=b+1;
    if(nxt_b>4)
    {
        nxt_a++;
        nxt_b=nxt_a+1;
    }
    memcpy(score_cache,score,sizeof(score));
    for(int i=a+1;i<=4;i++)
    {
        score[a]+=3;
        DFS(nxt_a,nxt_b,val*percent[a][b][0]); memcpy(score,score_cache,sizeof(score));
        score[a]++; score[b]++; 
        DFS(nxt_a,nxt_b,val*percent[a][b][1]); memcpy(score,score_cache,sizeof(score));
        score[b]+=3;
        DFS(nxt_a,nxt_b,val*percent[a][b][2]); memcpy(score,score_cache,sizeof(score));
    }
}
int main()
{
    for(int i=1;i<=4;i++)
    {
        string a;
        um[a]=i;
    }
    for(int i=0;i<6;i++)
    {
        string a,b; cin >> a,b;
        int num_a = um[a], num_b=um[b];
        for(int j=0;j<3;j++)
        {
            cin >> percent[num_a][num_b][j];
            percent[num_b][num_a][j] = 1 - percent[num_a][num_b][j];
        }
    }

}