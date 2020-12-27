#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
using namespace std;
int mn=1e9;
bool cmp(int a,int b)
{
    return a>b;
}
int lft(int a,int dist,int n)
{
    a = a-dist;
    if(a>=0) return a;
    else return n+a; 
}
int rght(int a,int dist, int n)
{
    a = a+dist;
    if(a<n) return a;
    else return a-n;
}
bool lft_check(int a,int lft_a,int dist, int b, int n)
{
    if(lft_a<a)
    {
        if(lft_a<=b && b <=a) return true;
    }
    else
    {
        if(b<=a || lft_a<=b) return true;
    }
    return false;
}
bool rght_check(int a,int rght_a,int dist, int b, int n)
{
    if(rght_a>a)
    {
        if(a<=b && b <=rght_a) return true;
    }
    else
    {
        if(b<=rght_a || a<=b) return true;
    }
    return false;
}
int BFS(int n, vector<int> weak, vector<int> dist)
{
    queue<pair<int,int>> q; q.push({0,0});
    int finish_check = 0;
    for(int i=0;i<weak.size();i++) finish_check |= 1<<i;
    while(!q.empty())
    {
        int a = q.front().first, check = q.front().second, origin = check; q.pop();
        if(a==dist.size()) return -1;
        for(int i=0;i<weak.size();i++)
        {
            if(check & 1<<i == 1<<i) continue;
            
            int start = weak[i],lft_a = lft(start,dist[a],n),rght_a = rght(start,dist[a],n);

            for(int j=0;j<weak.size();j++)
            {
                if(lft_check(start,lft_a,dist[a],weak[j],n)) check |= 1<<j;
            }

            if(check!=origin) q.push({a+1,check});
            if(check == finish_check) return a+1;
            check = origin;

            for(int j=0;j<weak.size();j++)
            {
                if(rght_check(start,rght_a,dist[a],weak[j],n)) check |= 1<<j;
            }

            if(check!=origin) q.push({a+1,check});
            if(check == finish_check) return a+1;
            check = origin;
        }
    }
    return -1;
}
int solution(int n, vector<int> weak, vector<int> dist)
{
    sort(dist.begin(),dist.end(),cmp);
    return BFS(n,weak,dist);
}