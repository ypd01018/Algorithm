#include <string>
#include <vector>
#include<algorithm>
using namespace std;
bool comp(string a, string b)
{
    if(a+b > b+a) return true;
    else return false;
}
string solution(vector<int> numbers) 
{
    string answer = "";
    vector<string> number;
    for(int i=0;i<numbers.size();i++)
    {
        number.push_back(to_string(numbers[i]));
    }
    sort(number.begin(),number.end(),comp);
    for(int i=0;i<number.size();i++) answer = answer+number[i];
    if(answer[0]=='0') answer="0";
    return answer;
}
int main()
{

}