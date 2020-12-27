#include <string>
#include <vector>

using namespace std;
vector<int> answer;
int N;
void go(int n)
{
    if(n==N) 
    {
        return;
    }
    
    vector<int> tmp;
    int a=1;
    for(int i=0;i<answer.size();i++)
    {
        a = (a+1)%2;
        tmp.push_back(a);
        tmp.push_back(answer[i]);
    }
    tmp.push_back(1);
    answer = tmp;

    go(n+1);
}
vector<int> solution(int n) 
{
    N=n;
    answer.push_back(0);
    go(1);
    return answer;
}
