#include<bits/stdc++.h>

using namespace std;
int N,K,check[100'003];
bool flag=false;
queue<pair<int,int>> q;
int main()
{
    int sec,a;
    cin >> N >> K;
    q.push(make_pair(N,0));
    while(!q.empty())
    {
        tie(a,sec) = q.front(); q.pop();
        if(check[a]) continue;
        check[a]=1;
        if(a==K)
        {
            cout << sec;
            break ;
        }
        if(a<K)
        {
            if(a*2<100001) q.push(make_pair(a*2,sec+1));
            if(a+1<100001) q.push(make_pair(a+1,sec+1));
        }
        if(a>-1) q.push(make_pair(a-1,sec+1));        
    }
}