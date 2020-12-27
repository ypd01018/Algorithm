#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int lft=1,rght;
bool check(vector<int> stones, int k, int n)
{
    int cnt=0;
    for(int i=0;i<stones.size();i++)
    {
        if(stones[i]<=n) cnt++;
        else cnt=0;
        if(cnt>=k) return true;
    }
    return false;
}
int solution(vector<int> stones, int k) 
{
    rght = *max_element(stones.begin(),stones.end());
    while(lft<=rght)
    {
        int mid = (lft+rght)/2;
        if(check(stones,k,mid)) rght = mid-1;
        else lft = mid+1; 
    }
    return lft;
}