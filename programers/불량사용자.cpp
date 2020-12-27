#include <string>
#include <vector>
#include<iostream>
using namespace std;
int visited[10],answer,done[600];
bool check(string a, string b)
{
    if(a.size()!= b.size()) return false;
    for(int i=0;i<a.size();i++)
    {
        // cout << i <<a[i]<<b[i] <<(b[i]=='*')<<(a[i]!=b[i])<<' ';
        if(b[i]=='*') continue;
        if(a[i]!=b[i]) return false;
    }//cout << endl;
    return true;
}
int make_two(int n)
{
    int one =1,total=0;
    for(int i=0;i<n;i++)
    {
        total += visited[i]*one;
        one*=2;
    }
    return total;
}
void dfs(int n, vector<string> user_id, vector<string> banned_id)
{
    if(n==banned_id.size())
    {
        int n = make_two(user_id.size());
        if(done[n]) return;
        done[n]=1;
        answer++;
        return;
    }
    for(int i=0;i<user_id.size();i++)
    {
        // cout<<endl << i<<" turn" << endl;
        if(visited[i] || !check(user_id[i],banned_id[n])) continue;
        visited[i]=1;
        dfs(n+1,user_id,banned_id);
        visited[i]=0;
    }
}
int solution(vector<string> user_id, vector<string> banned_id) 
{
    dfs(0,user_id,banned_id);
    return answer;
}
int main()
{
    vector<string> user_id;vector<string> banned_id;
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        string a; cin >> a;
        user_id.push_back(a);
    }
    for(int i=0;i<m;i++)
    {
        string a; cin >> a;
        banned_id.push_back(a);
    }
    cout << solution(user_id,banned_id);
}