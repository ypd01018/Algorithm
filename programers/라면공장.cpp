#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> q;
int solution(int stock, vector<int> dates, vector<int> supplies, int k) 
{
    int day,idx=0; int s = stock,cnt=0;
    for(int day = 0;day<k;day++)
    {
        if(day==dates[idx])q.push(supplies[idx++]);
        s--;
        if(s<0)
        {
            s += q.top(); q.pop(); cnt++;
        }
    }
    return cnt;
}

int main()
{
    
}