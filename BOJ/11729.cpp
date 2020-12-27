#include<iostream>
#include<stack>
#include<queue>
#define endl "\n"

using namespace std;
stack<int> stk[3];
queue<int> q;
int cnt = 0;
void hanoi(int a, int b, int n)
{
    cnt ++ ;
    if(n == 1) 
    {
        int temp = stk[a].top(); stk[a].pop();
        stk[b].push(temp);
        //cout << a+1 << " " << b+1 << endl;
        q.push(a+1); q.push(b+1); 
        return ;
    }
    int c = 3-a-b;
    hanoi(a,c,n-1);
    //cout << a+1 << " " << b+1 << endl;
    q.push(a+1); q.push(b+1);
    hanoi(c, b, n-1);
}

int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);


    int num;
    cin >> num;

    for(int i=num; i>0 ; i--)
    {
        stk[0].push(i);
    }

    hanoi(0,2,num);
    cout << cnt << endl;
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
        cout << q.front() << endl;
        q.pop();
    }
}