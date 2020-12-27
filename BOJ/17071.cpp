#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int limit = 500'000;
int N,K,ans=-1,visited_big[500'002],visited_small[500'002],mn=INT_MAX;
queue<pair<int,int>> q;
void check(int big)
{
    int big_sec = visited_big[big], small_sec = visited_small[big];
    if(big_sec%2 != small_sec%2) return;
    if(big_sec > small_sec) return;
    mn = min(mn,small_sec);
}
bool BFS()
{
    q.push({K,1});
    while(!q.empty())
    {
        int sec = q.front().second, small =q.front().first;  q.pop();
        visited_small[small] = sec;
        int nxt_small = small + sec;
        if(nxt_small > limit) continue;
        q.push({nxt_small,sec+1});
    }

    q.push({N,1}); visited_big[N]=1;
    while(!q.empty())
    {
        int big = q.front().first,sec = q.front().second; q.pop();
        
        int big_plus=big+1,big_minu=big-1,big_mul=big*2;
        if(big_plus<=limit && !visited_big[big_plus]) 
        {
            visited_big[big_plus]=sec+1;
            if(visited_small[big_plus]) check(big_plus);
            q.push({big_plus,sec+1});
        }
        if(big_minu>=0 && !visited_big[big_minu]) 
        {
            visited_big[big_minu]=sec+1;
            if(visited_small[big_minu]) check(big_minu);
            q.push({big_minu,sec+1});
        }
        if(big_mul<=limit && !visited_big[big_mul]) 
        {
            visited_big[big_mul]=sec+1;
            if(visited_small[big_mul]) check(big_mul);
            q.push({big_mul,sec+1});
        }
    }
    return false;
}
int main()
{
    cin >> N >>K;
    if (N==K) cout << 0;
    else 
    {
        BFS();
        if(mn==INT_MAX) cout <<-1;
        else cout << mn-1;
    }
}