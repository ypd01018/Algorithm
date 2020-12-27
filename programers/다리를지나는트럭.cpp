#include <string>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;
queue<pair<int,int>> q;
int sec=0,q_weight;
int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0,idx=0;
    while(idx!=truck_weights.size())
    {
        sec++;
        if(sec==q.front().second)
        {
            q_weight-=q.front().first;
            //cout << q.front().first << " is pop when " << sec<<endl;
            q.pop();
        }
        if(q_weight+truck_weights[idx]<=weight)
        {
            q.push({truck_weights[idx],sec+bridge_length});
            q_weight+=truck_weights[idx];
            idx++;
        }        
        
    }
    while(!q.empty())
    {
        sec = q.front().second; q.pop();
    }
    return sec;
}

int main()
{
    int a,b,N; cin >> a >> b >> N;
    vector<int> truck_weights;
    for(int i=0;i<N;i++)
    {
        int c; cin >> c;
        truck_weights.push_back(c);
    }
    cout << solution(a,b,truck_weights);
}