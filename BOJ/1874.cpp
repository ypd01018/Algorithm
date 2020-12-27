#include<iostream>
#define endl "\n"
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int n,a,b,cnt=0,target,temp;
    bool flag=true;
    cin >> n;
    queue<int> q,q2,q_sol;
    queue<char> q_pm;
    stack<int> stk;
    for (int i=1;i<n+1;i++)
    {
        cin >> a;
        q.push(a);
        q2.push(i);
    }
    while(q.empty()!=1)
    {
        target=q.front();
        q.pop();

        if(q2.front() <= target && q2.empty()!=1)
        {
            while(  (stk.empty()==1  || stk.top()!=target) )
            {
            temp=q2.front();
            q2.pop();
            stk.push(temp);
            q_pm.push('+');
            }
        }
        else
        {
            if( stk.empty()==1  ||stk.top()!=target)
            {
                flag=false;
                break;
            }
        }
        if(stk.empty()!=1)
        {
        temp=stk.top();
        stk.pop();
        q_pm.push('-');
        q_sol.push(temp);
        }
   
    }


    if(flag==true)
        while(q_pm.empty()!=1)
        {
            cout<< q_pm.front()<<endl;
            q_pm.pop();
        }   
    else cout <<"NO";
}