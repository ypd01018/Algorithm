#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,K,visited[100'002];
int mx_sec = INT_MAX;
queue<pair<int,int>> q;

void go(int location,int sec)
{
    if(location<0 || location>100'000) return;
    if(visited[location]) return;
    q.push({location,sec+1});
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> K; if(N==K) {cout << "0 1"; return 0;}
    q.push({N,0});
    visited[N]=1;
    while(!q.empty())
    {
        int location=q.front().first, sec=q.front().second; q.pop();
        visited[location]++;
        if(sec>mx_sec) break;
        if(location == K) mx_sec=sec;
        go(location-1,sec); go(location+1,sec); go(location*2,sec);
    }
    cout <<mx_sec<<endl;
    cout << visited[K];
}