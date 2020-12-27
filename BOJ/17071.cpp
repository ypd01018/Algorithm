#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int limit = 500'000;
int N,K,visited_big[2][500'002],visited_small[500'002],mn=INT_MAX;
queue<pair<int,int>> q;
void check(int big,int sec)
{
    int big_sec = visited_big[sec%2][big], small_sec = visited_small[big];
    if(big_sec%2 != small_sec%2) return;
    if(big_sec > small_sec) return;
    mn = min(mn,small_sec);
}
void nxt_big(int big,int sec)
{
    if(big>=0 && big<=limit && visited_big[(sec+1)%2][big]<0) 
    {
        visited_big[(sec+1)%2][big]=sec+1;
        q.push({big,sec+1});
    }
}
void BFS()
{
    q.push({K,0});
    memset(visited_small,-1,sizeof(visited_small));
    while(!q.empty())
    {
        int sec = q.front().second, small =q.front().first;  q.pop();
        visited_small[small] = sec;
        int nxt_small = small + sec + 1;
        if(nxt_small > limit) continue;
        q.push({nxt_small,sec+1});
    }
    memset(visited_big,-1,sizeof(visited_big));
    q.push({N,0}); visited_big[0%2][N]=0;
    while(!q.empty())
    {
        int big = q.front().first,sec = q.front().second; q.pop();
        if(visited_small[big]>=0) check(big,sec);
        int big_plus=big+1,big_minu=big-1,big_mul=big*2;
        nxt_big(big_plus,sec);
        nxt_big(big_minu,sec);
        nxt_big(big_mul,sec);
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >>K;
    if (N==K) cout << 0;
    else 
    {
        BFS();
        if(mn==INT_MAX) cout <<-1;
        else cout << mn;
    }
}