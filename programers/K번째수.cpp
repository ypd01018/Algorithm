#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    for(int i=0;i<commands.size();i++)
    {
        vector<int> tmp;
        for(int j=commands[i][0];j<=commands[i][1];j++)
        {
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[-1+commands[i][2]]);
    }
    for(int i=0;i<answer.size();i++) cout << answer[i]<<' ';
    return answer;
}

int main()
{
    int N; cin >> N;
    vector<int> array;
    for(int i=0;i<N;i++) 
    {int a; cin >> a;array.push_back(a);}
    vector<vector<int>> commands;
    commands.resize(3);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int a; cin >> a;
            commands[i].push_back(a);
        }
    }
    solution(array,commands);

}