#include<iostream>
#define endl "\n"

#define open_2 1
#define close_2 2
#define open_3 3
#define close_3 4

#define plus2 1
#define mul2 2
#define plus3 3
#define mul3 4

#define plu 1
#define mul 2
#include<stack>
using namespace std;

stack<int> stk;
stack<char> stk_1,stk_2;
string input;
int total = 0, temp = 1,  flag = true;
void ex();
int main()
{
    cin >> input;
    string::iterator iter = input.begin();
    string::iterator iter_next;;

    for(auto i : input)
    {   
        switch (i)
        {
            case '(':
                temp = temp*2;
                stk_1.push(i);
                if(iter != input.end() && *(iter+1) == ')')
                {
                    total += temp;
                }
                break;
            case ')':
                if(stk_1.empty()==1) ex();
                stk_1.pop();
                temp /=2;
                break;
            case '[':
                temp = temp*3;
                stk_2.push(i);
                if(iter != input.end() && *(iter+1) == ']')
                {
                    total += temp;
                }
                break;
            case ']':
                if(stk_2.empty()==1) ex();
                stk_2.pop();
                temp /=3;
                break;
            default:
                break;
        }
        iter++;
    }
    if(stk_1.empty()!=1 || stk_2.empty()!=1) ex();
    cout << total;

}   
void ex()
{
    cout << 0;
    exit(0);
}