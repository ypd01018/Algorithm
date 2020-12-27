#include <string>
#include <vector>
#include<stack>
#include<iostream>
using namespace std;
stack<pair<int,int>> stk;
int num_idx[100002];

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.resize(prices.size());
    for(int i=prices.size()-1;i>=0;i--)
    {
        while(!stk.empty())
        {
            if(stk.top().first < prices[i]) break;
             stk.pop();
        }
        if(stk.empty())
        {
            stk.push({prices[i],i});
            answer[i]=prices.size()-1-i;
            continue;
        }
        answer[i]=stk.top().second-i;
        stk.push({prices[i],i});
    }

    // for(int i=0;i<answer.size();i++) cout << answer[i] << ' ';
    return answer;
}

// int main()
// {
//     vector<int> v;
//     for(int i=0;i<5;i++) {int a; cin >> a; v.push_back(a);}
//     solution(v);
// }