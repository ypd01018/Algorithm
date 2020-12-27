#include <string>
#include <vector>
#include <stack>
using namespace std;
bool balance(string u)
{
    stack<int> stk;
    for(int i=0;i<u.size();i++)
    {
        if(u[i]=='(') stk.push(1);
        else 
        {
            if(stk.empty()) return false;
            stk.pop();
        }
    }
    return true;
}
string four_four(string u)
{
    string ret;
    for(int i=1;i<u.size()-1;i++)
    {
        if(u[i]=='(') ret.push_back(')');
        else ret.push_back('(');
    }
    return ret;
}
string go(string p)
{
    if(p.size()==0) return "";

    int cnt=0;
    string u,v;
    bool flag = true;
    for(int i=0;i<p.size();i++)
    {
        if(flag)
        {
            u.push_back(p[i]);
            if(p[i]=='(') cnt++;
            else cnt--;
            if(cnt==0) flag = false;
        }
        else v.push_back(p[i]);
    }
    bool balance_true = balance(u);
    if(balance_true) 
    {
        v = go(v);
        u.append(v);
        return u;
    }
    else
    {
        string tmp = "(";
        tmp.append(go(v));
        tmp.push_back(')');
        tmp.append(four_four(u));
        return tmp;
    }
    
}
string solution(string p) 
{
    string answer =go(p);
    return answer;
}