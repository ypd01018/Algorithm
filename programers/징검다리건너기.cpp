#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[200020];
int mn=1e9;
int solution(vector<int> stones, int k) 
{
    for(int i=0;i<stones.size();i++)
    {
        cout << i <<':'<<stones[i]-k<<endl;
    }
    return mn;
}   