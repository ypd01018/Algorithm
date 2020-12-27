#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int lock_empty;
vector<vector<int>> rotate_lft(vector<vector<int>> key)
{
    int N = key.size(); queue<int> q;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            q.push(key[i][j]);
        }
    }
    for(int i=N-1;i>=0;i--)
    {
        for(int j=0;j<N;j++)
        {
            key[j][i] = q.front();
            q.pop();
        }
    }
    return key;
}
vector<vector<int>> extend_lock(vector<vector<int>> lock,vector<vector<int>> key)
{
    if(key.size()<=lock.size()) return lock;
    vector<vector<int>> new_lock;
    new_lock.resize(key.size());
    for(int i=0;i<key.size();i++)
    {
        for(int j=0;j<key.size();j++)
        {
            if(i>=lock.size() || j >= lock.size()) new_lock[i].push_back(-1);
            else new_lock[i].push_back(lock[i][j]);
        }
    }
    return new_lock;
}
vector<vector<int>> extend_key(vector<vector<int>> lock,vector<vector<int>> key)
{
    if(key.size()==lock.size()) return key;
    vector<vector<int>> new_key;
    new_key.resize(lock.size());
    for(int i=0;i<lock.size();i++)
    {
        for(int j=0;j<lock.size();j++)
        {
            if(i>=key.size() || j >= key.size()) new_key[i].push_back(-1);
            else new_key[i].push_back(key[i][j]);
        }
    }
    return new_key;
}
bool matching_a(int y, int x,vector<vector<int>> key, vector<vector<int>> lock) // 좌상
{
    int cnt=0;
    for(int i=0;i<lock.size();i++)
    {
        for(int j=0;j<lock.size();j++)
        {
            if(y+i>= key.size() || x+j>=key.size()) continue;

            if(lock[i][j]==0 && key[y+i][x+j]==0) return false;
            if(lock[i][j]==1 && key[y+i][x+j]==1) return false;
            if(lock[i][j]==0 && key[y+i][x+j]==1) cnt++;
        }
    }
    if(cnt<lock_empty) return false;
    return true;
}
bool matching_b(int y, int x,vector<vector<int>> key, vector<vector<int>> lock) //우하
{
    int cnt=0;
    for(int i=0;i<lock.size();i++)
    {
        for(int j=0;j<lock.size();j++)
        {            
            if(i<y || j<x) continue;
            if(lock[i][j]==0 && key[i-y][j-x]==0) return false;
            if(lock[i][j]==1 && key[i-y][j-x]==1) return false;
            if(lock[i][j]==0 && key[i-y][j-x]==1) cnt++;
        }
    }
    if(cnt<lock_empty) return false;
    return true;
}
bool matching_c(int y, int x,vector<vector<int>> key, vector<vector<int>> lock) //우상
{
    int cnt=0;
    for(int i=0;i<lock.size();i++)
    {
        for(int j=0;j<lock.size();j++)
        {            
            if(key.size()<=i-y || i-y<0 || j+x>=key.size()) continue;
            if(lock[i][j]==0 && key[i-y][j+x]==0) return false;
            if(lock[i][j]==1 && key[i-y][j+x]==1) return false;
            if(lock[i][j]==0 && key[i-y][j+x]==1) cnt++;
        }
    }
    if(cnt<lock_empty) return false;
    return true;
}
bool matching_d(int y, int x,vector<vector<int>> key, vector<vector<int>> lock) //우하
{
    int cnt=0;
    for(int i=0;i<lock.size();i++)
    {
        for(int j=0;j<lock.size();j++)
        {            
            if(i+y>=key.size() || j-x<0) continue;
            if(lock[i][j]==0 && key[i+y][j-x]==0) return false;
            if(lock[i][j]==1 && key[i+y][j-x]==1) return false;
            if(lock[i][j]==0 && key[i+y][j-x]==1) cnt++;
        }
    }
    if(cnt<lock_empty) return false;
    return true;
}
bool matching_start(vector<vector<int>> key, vector<vector<int>> lock)
{
    int N = max(lock.size(),key.size());
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int y=i,x=j;
            if(matching_a(y,x,key,lock)) return true;
            if(matching_b(y,x,key,lock)) return true;
            if(matching_c(y,x,key,lock)) return true;
            if(matching_d(y,x,key,lock)) return true;
        }
    }
    return false;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) 
{
    for(int i=0;i<lock.size();i++)
    {
        for(int j=0;j<lock.size();j++)
        {
            if(lock[i][j]==0) lock_empty++;
        }
    }
    lock = extend_lock(lock,key);
    key = extend_key(lock,key);
    for(int i=0;i<4;i++)
    {
        if(matching_start(key,lock)) return true;
        key = rotate_lft(key);
    }

    return false;
}