#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
queue<int> q;
vector<int> v;
void que()
{
    string cmd;
    cin >> cmd;
    if(cmd =="push")
    {
        int tmp; cin >> tmp;
        q.push(tmp);
    }
    else if(cmd=="pop")
    {
        if(q.empty())
        {
            v.push_back(-1); return;
        }
        v.push_back(q.front()); q.pop();
    }
    else if(cmd == "size")
    {
        v.push_back(q.size());
    }
    else if(cmd=="empty")
    {
        v.push_back(q.empty());
    }
    else if(cmd == "front")
    {
        if(q.empty())
        {
            v.push_back(-1);
            return;
        }
        v.push_back(q.front());
    }
    else
    {
        if(q.empty())
        {
            v.push_back(-1);
            return;
        }
        v.push_back(q.back());
    }
    
}
int main()
{
    int N;
    cin >> N;
    for(int i=0;i<N;i++) que();
    for(int i=0;i<v.size();i++)
    {
        cout << v[i] <<endl;
    }

}