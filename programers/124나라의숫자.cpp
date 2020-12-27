#include <string>
#include <vector>
#include<math.h>
#include<iostream>
using namespace std;
string answer = "";
void go(int n)
{
    if(n>=3) go((n/3)-1);
    int a = pow(2,n%3)+'0';
    answer.push_back(a);
}
string solution(int n) 
{
    go(n-1);
    return answer;
}
int main()
{
    int n; cin >> n;
    cout << solution(n);
}