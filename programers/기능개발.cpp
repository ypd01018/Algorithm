#include <string>
#include <vector>
#include<iostream>
#define endl "\n"
using namespace std;
int state=-1;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    while(state!=progresses.size()-1)
    {
        int cnt=0;
        for(int i=0;i<progresses.size();i++)
        {
            if(state>=i) continue;

            if(progresses[i]<100) progresses[i] += speeds[i];
            if(progresses[i]>=100 && state == i-1)
            {
                cnt++;
                state=i;
            }
        }
        if(cnt) answer.push_back(cnt);
    }
    return answer;
}

// int main()
// {
//     int N; cin >> N;
//     vector<int> v,v2;
//     for(int i=0;i<N;i++)
//     {
//         int a; cin >> a;
//         v.push_back(a);
//     }
//         for(int i=0;i<N;i++)
//     {
//         int a; cin >> a;
//         v2.push_back(a);
//     }
//     v = solution(v,v2);
//     for(int i=0;i<v.size();i++) cout << v[i] << ' ';
// }