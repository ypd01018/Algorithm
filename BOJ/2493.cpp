#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int top_n, h;
stack<pair<int,int>> stk;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> top_n;

    for(int i=1 ; i<top_n+1; i++)
    {
        cin >> h ;
        while(1)
        {
            if(stk.empty()==1)
            { 
                stk.push(make_pair(i,h));
                cout << 0 <<" ";
                break;
            }

            if(stk.top().second < h)
            {
                stk.pop();
            }
            else
            {
                cout << stk.top().first<<" ";
                stk.push(make_pair(i,h));
                break;
            }
        } 
    }
}