#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
int cnt[510];
double fail[510];
vector<pair<double,int>> ans;
bool cmp(pair<double,int> a,pair<double,int> b)
{
    if(a.first > b.first) return true;
    else if(a.first < b.first) return false;
    else
    {
        if(a.second<b.second) return true;
        else return false;
    }
}
vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;
    for(int i=0;i<stages.size();i++) cnt[stages[i]]++;
    int total = stages.size();
    for(int i=1;i<=N;i++)
    {
        ans.push_back({((double)cnt[i]/(double)total),i});
        total -= cnt[i];
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++) answer.push_back(ans[i].second);
    return answer;
}
