#include<iostream>
#include <string>
#include <vector>
#include <map>
#include<queue>
using namespace std;
int cnt,a,ten=10;
vector<int> ans,v;
pair<int,int> num[100002];
map<int,int> mp;
priority_queue<pair<int,int> > pq;
vector<int> solution(string s) 
{
    for(int i=1;i<s.size()-1;i++)
    {
        // cout << i <<'('<<s[i]<< "):" << cnt << endl;
        if(s[i]=='{') 
        {
            cnt = 1; a=0;v.clear();
        }
        else if('0'<=s[i] && s[i]<='9')
        {
            a *= ten; 
            a += s[i] - '0';
        }
        else if(s[i]==',')
        {
            v.push_back(a);
            a=0;
            cnt++;
        }
        else if(s[i]=='}')
        {
            v.push_back(a);       
            a=0;
            for(int j=0;j<v.size();j++)
            {
                // cout <<"val:"<<v[j] << "   cnt:" << cnt << endl; 
                if(mp[v[j]] ==0 || mp[v[j]] > cnt) mp[v[j]] = cnt;
            }
        }
    }
    map<int,int>::iterator iter = mp.begin();
    for(iter;iter!=mp.end();iter++)
    {
        // cout << iter->first << ',' << iter->second << endl;
        pq.push({-1*iter->second,iter->first});
    }
    while(!pq.empty())
    {
        cout << pq.top().second << endl;
        ans.push_back(pq.top().second); pq.pop();
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    solution(s);
}