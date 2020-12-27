#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,score[10002],dp[10002][2],mx;
vector<int> v[10002],ans;

void go(int a)
{
    if(v[a].size()<=1)
    {
        dp[a][0]=0;
        dp[a][1]=score[a];
        return;
    }
    dp[a][0]=dp[a][1]=0;
    for(int i=0;i<v[a].size();i++)
    {
        int to = v[a][i];
        if(dp[to][0]==-1) go(to);
        else continue;  
        dp[a][0] += max(dp[to][0],dp[to][1]);
        dp[a][1] += dp[to][0];
    }
    dp[a][1]+= score[a];
    mx = max(dp[a][1],dp[a][0]);
}
void print_ans(int a,int from,bool flag)
{
    if(flag) ans.push_back(a);
    if(v[a].size()<=1) return;
    if(flag)
    {
        for(int i=0;i<v[a].size();i++)
        {
            int to = v[a][i];
            if(to!=from)print_ans(to,a,false);
        }
    }
    else
    {
        for(int i=0;i<v[a].size();i++)
        {
            int to = v[a][i];
            if(to==from) continue;
            if(dp[to][0]>dp[to][1]) print_ans(to,a,false);
            else print_ans(to,a,true);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >> N;
    for(int i=1;i<=N;i++) cin >> score[i];
    for(int i=0;i<N-1;i++)
    {
        int from,to; cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    for(int i=1;i<=N;i++)
    {
        if(v[i].size()<=1) continue;
        go(i);
        if(dp[i][0]>dp[i][1]) print_ans(i,0,false);
        else print_ans(i,0,true);
        break;
    }
    sort(ans.begin(),ans.end());
    cout << mx<<endl;
    for(int i=0;i<ans.size();i++) cout << ans[i] << ' ';
}