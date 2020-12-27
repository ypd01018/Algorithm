#include <string>
#include <vector>
#include<iostream>
#include<stack>
using namespace std;
stack<pair<int,int>> stk;
vector<int> solution(vector<int> heights) 
{
    vector<int> answer;

    for(int i=0;i<heights.size();i++)
    {
        while(!stk.empty() && stk.top().first <= heights[i]) stk.pop();

        if(stk.empty())
        {
            answer.push_back(0);
        }
        else
        {
            answer.push_back(stk.top().second);
        }
        stk.push({heights[i],i+1});
    }
    return answer;
}

int main()
{
    vector<int> v;
    int N; cin >> N;
    for(int i=0;i<N;i++)
    {
        int a; cin >> a;
        v.push_back(a);
    }
    v=solution(v);
    for(int i=0;i<v.size();i++) cout << v[i] << ' ';
}