#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, K, mx;
int arr[30];
void DFS(int idx, int eat, int energy){
    if(idx == N){
        mx = max(mx,energy);
        return;
    }
    if(!eat) DFS(idx+1, eat, energy);
    
    eat += arr[idx];
    if(eat>=K) {
        energy += eat - K;
        eat = 0;
    }
    DFS(idx+1, eat, energy);
}
int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    DFS(0,0,0);
    cout << mx;
}