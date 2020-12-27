#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N;
vector<pair<string,int>> ans;
string get_ans(int target_sec)
{
    for(int i=ans.size()-1;i>=0;i--)
    {
        if(target_sec>ans[i].second) return ans[i].first;
    }
    return "";
}
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        string cmd,val; int sec;
        cin >> cmd >> val >> sec;
        if(cmd == "type") 
        {
            string push_val;
            if(ans.size())push_val = ans.back().first+val;
            else push_val = val; 
            ans.push_back({push_val,sec});
        }
        else
        {
            ans.push_back({get_ans(sec-atoi(val.c_str())),sec});
        }
    }
    for(int i=0;i<ans.size();i++) cout << ans[i].first<<','<<ans[i].second << endl;
    cout << ans.back().first;
}