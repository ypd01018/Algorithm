#include <iostream>
#include <stack>
#define endl "\n"
using namespace std;
stack<int> stk;
int N;
int main()  
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int cmd; cin >> cmd;
        if(!cmd)
        {
            int a; cin >> a;
            if(stk.size()>=10)
            {
                cout << "overflow"<<endl;
                continue;
            }
            stk.push(a);
        }
        else if(cmd==1)
        {
            if(stk.empty())
            {
                cout << "underflow" <<endl;
                continue;
            }
            stk.pop();
        }
        else break;
    }
    stack<int> ans;
    while(!stk.empty())
    {
        ans.push(stk.top());stk.pop();
    }
    while(!ans.empty())
    {
        cout << ans.top() << ' '; ans.pop();
    }
	return 0;
}