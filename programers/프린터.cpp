#include <string>
#include <vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
queue<pair<int,int>> q;
int mx,cnt[10],n;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i=0;i<priorities.size();i++)
    {
        q.push({priorities[i],i});
        mx = max(mx,priorities[i]);
        cnt[priorities[i]]++;
    }

    while(!q.empty())
    {
        int priority = q.front().first, locate = q.front().second; q.pop();
        // cout <<mx << ' ' <<priority << ' ' << locate << endl;
        if(priority==mx)
        {
            n++;
            if(locate == location) return n;
            cnt[priority]--;
            for(int i=priority;i>=0;i--)
            {
                if(cnt[i]>0)
                {
                    mx = i;
                    break;
                }
            }
        }
        else
        {
            q.push({priority,locate});
        }
        
    }
    return answer;
}

// int main()
// {
//     int N,a; cin >> N >> a;
//     vector<int> v;
//     for(int i=0;i<N;i++)
//     {
//         int b;
//         cin >> b; v.push_back(b);
//     }
//     cout << solution(v,a);
// }