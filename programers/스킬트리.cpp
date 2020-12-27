#include <string>
#include <vector>
#include<iostream>
#include<memory.h>
using namespace std;
int origin[30],indegree[30];
vector<int> node[30];
bool go(string skill,string skill_trees)
{
    for(int i=0;i<skill_trees.size();i++)
    {
        int num = skill_trees[i]-'A';
        if(indegree[num]>0) return false;
        for(int j=0;j<node[num].size();j++)
        {
            indegree[node[num][j]]--;
        }
    }
    return true;
}
int solution(string skill, vector<string> skill_trees) 
{
    int answer = 0;
    for(int i=0;i<skill.size()-1;i++)
    {
        node[skill[i]-'A'].push_back(skill[i+1]-'A');
        origin[skill[i+1]-'A']++;
    }
    for(int i=0;i<skill_trees.size();i++)
    {
        memcpy(indegree,origin,sizeof(origin));
        if(go(skill,skill_trees[i])) answer++;
    }
    return answer;
}

int main()
{
    vector<string> a;
    a.push_back("BACDE"); a.push_back("CBADF"); a.push_back("AECB"); a.push_back("BDA");
    cout << solution("CBD",a);
}