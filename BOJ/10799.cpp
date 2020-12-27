#include<iostream>
#define endl "\n"
#define open 1
#define close 2
#include<stack>
#include<queue>
using namespace std;
string input;
stack<char> stk;
int Fe_num=0, pre = 0, total=0;
int main()
{
    cin >> input;

    for (auto i : input)
    {
            if( i == '(')
            {
                stk.push(i);
                pre = open;
                total++;
            }
            else
            {
                stk.pop();
                if(pre == open)
                {
                    total--;
                    Fe_num = stk.size();
                    total = total + Fe_num;
                }
                pre = close;
                
            }
    }

    cout << total << endl;

}
