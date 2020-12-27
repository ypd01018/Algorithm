#include <string>
#include <vector>
#include <unordered_map>
#include <memory.h>
#include <iostream>
#include <bitset>
using namespace std;
int bit[1<<8],cnt,visited[10];
unordered_map<string,int> mp;
vector<int> v;
bool check(vector<int> v, int N)
{
    int new_bit = 0;
    for(int i=0;i<v.size();i++) new_bit += 1<<v[i];
    for(int i=1;i<=(1<<N);i++) 
    {
        if(!bit[i]||i==new_bit || (new_bit&i)!=i) continue;
        return false;        
    }
    return true;
}
void go(int start, int a,int n,vector<vector<string>> relation)
{
    if(a==n)
    {
        if(!check(v,relation[0].size())) return;
        mp.clear();
        for(int i=0;i<relation.size();i++)
        {
            string key="";
            for(int j=0;j<v.size();j++) key.append(relation[i][v[j]]);
            if(mp[key]) return;
            mp[key]++;
        }
        int new_bit = 0;
        for(int i=0;i<v.size();i++) new_bit += 1<<v[i];
        bit[new_bit]=1;
        cnt++;
        return;
    }
    for(int i=start;i<relation[0].size();i++)
    {
        if(visited[i]) continue;
        v.push_back(i); visited[i]=1;
        go(i+1,a+1,n,relation);
        v.pop_back(); visited[i]=0;
    }
}
int solution(vector<vector<string>> relation) 
{
    for(int i=0;i<relation[0].size();i++) go(0,0,i+1,relation);
    return cnt;
}