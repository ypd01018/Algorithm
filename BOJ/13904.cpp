#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,total_score;
vector<pair<int,int>> v;
int day_score[1001];
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.second>b.second) return true;
    else if(a.second<b.second) return false;
    else
    {
        if(a.first<b.first) return true;
        else return false;
    }
     
}
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)
    {
        int day = v[i].first, score = v[i].second;
        for(int j=day;j>=1;j--)
        {
            if(day_score[j]) continue;
            day_score[j]=score;
            total_score+=score;
            break;
        }
    }
    cout << total_score;

}