#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,mat[1500];
void print_()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(j==0)cout << mat[N-i-1]+1<<' ';
            else cout << mat[N+j-1]+1<<' ';
        }cout << endl;
    }
}
void day()
{
    int arr[3],idx=0;
    for(int i=0;i<3;i++)cin >> arr[i];
    for(int i=0;i<(N*2)-1;i++)
    {
        while(!arr[idx]) idx++; arr[idx]--;
        mat[i] += idx;
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<M;i++) day();
    print_();
}