#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N;
stack<int> s;
queue<int> q;
void stk_cmd()
{
    string input;
    cin >> input;
    int cmd;
    if(input=="push")
    {
        int tmp; cin >> tmp;
        s.push(tmp);
    }
    else if(input=="pop")
    {
        if(s.empty())
        {
            q.push(-1);
            return;
        }
        q.push(s.top()); 
        s.pop();
    }
    else if(input=="top")
    {
        if(s.size()==0)
        {
            q.push(-1);
            return;
        }
        q.push(s.top());
    }
    else if(input =="size")
    {
        q.push(s.size());
    }
    else
    {
        q.push(s.empty());
    }
}

int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    stk_cmd();

    while(!q.empty())
    {
        cout << q.front()<<endl; q.pop();
    }
}