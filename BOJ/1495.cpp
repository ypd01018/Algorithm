#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,S,M,mx=-1;
int visited[101][1010];
int plmi[2]={-1,1};
int arr[102];
queue<pair<int,int>> q;
int main()
{
    cin >> N >> S >> M;
    for(int i=0;i<N;i++) cin >> arr[i];
    q.push({0,S});
    while(!q.empty())
    {
        int song_num = q.front().first, volume = q.front().second; q.pop();
        if(song_num == N)
        {
            mx = max(volume,mx);
            continue;
        }
        for(int i=0;i<2;i++)
        {
            int new_volume = volume + (arr[song_num]*plmi[i]);
            if(new_volume<0 || new_volume>M || visited[song_num+1][new_volume]) continue;
            visited[song_num+1][new_volume] = 1;
            q.push({song_num+1,new_volume});
        }
    }
    cout << mx;
}