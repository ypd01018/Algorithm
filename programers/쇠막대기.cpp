#include <string>
#include <vector>
#include<iostream>
using namespace std;
int a;
int solution(string arrangement) 
{
    int answer = 0;
    for(int i=0;i<arrangement.size();i++)
    {
        if(arrangement[i]=='(' && i<arrangement.size()-1&& arrangement[i+1]==')') 
        {
            answer += a;
            i++;
        }
        else
        {
            if(arrangement[i]=='(') a++;
            else 
            {
                a--;
                answer++;
            }
        }
    }
    return answer;
}

int main()
{
    string a="()(((()())(())()))(())";
    cout << solution(a);
}