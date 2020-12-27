#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;
priority_queue<int> q;
int solution(vector<int> scoville, int K) 
{
    for(int i=0;i<scoville.size();i++)
    {
        q.push(-1*scoville[i]);
    }
    int cnt=0;
    while(!q.empty())
    {
        int mn = q.top()*-1; q.pop();
        if(mn>=K) return cnt;
        cnt++;
        if(q.empty()) return -1;
        int mn_second = q.top()*-1; q.pop();
        int new_scoville = mn+(mn_second*2);
        q.push(-1*new_scoville);
    }
    return -1;
}
int main()
{
    vector<int> scoville; int K;
    int N; cin >> N >>K;
    for(int i=0;i<N;i++)
    {
        int a ; cin >> a;
        scoville.push_back(a);
    }
    cout << solution(scoville,K);
}