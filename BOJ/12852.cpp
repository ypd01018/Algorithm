#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,mn=1e9;
int visited[1000002];
vector<int> v,ans;
void print_ans(int a)
{
    if(!a) return;
    cout << a << ' ';
    if( !(a%3) && visited[a/3] == visited[a]-1) print_ans(a/3);
    else if( !(a%2) && visited[a/2] == visited[a]-1) print_ans(a/2);
    else if(a>=1) print_ans(a-1);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=2;i<=N;i++)
    {
        visited[i] = visited[i-1]+1;
        if(!(i%2)) visited[i] = min(visited[i/2]+1,visited[i]);
        if(!(i%3)) visited[i] = min(visited[i/3]+1,visited[i]);
    }
    cout << visited[N] << endl;
    print_ans(N);
}