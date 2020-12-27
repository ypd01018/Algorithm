#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int F, S, G, U, D, stair[1'000'003];
bool visited[1'000'003];
queue<int> q;
//F = 총 층 , S= 현재 층, G=목표위치, U=위로 U층 올라감, D=아래로 D층 내려감
bool sol()
{
    while(!q.empty())
    {
        int y = q.front(); q.pop();
        if(y == G)
        {
            return true;
        }

        int uy = y+U,dy = y-D;
        if(uy <= F && uy >=1 && !visited[uy])
        {
            visited[uy]=1;
            stair[uy] = stair[y]+1;
            q.push(uy);
        }
        if( dy<=F &&dy >= 1 && !visited[dy])
        {
            visited[dy]=1;
            stair[dy] = stair[y]+1;
            q.push(dy);
        }
    }
    return false;
}
int main()
{
    cin >> F>>S>>G>>U>>D;
    
    q.push(S);
    visited[S]=1;
    if(sol()) cout << stair[G];
    else cout <<"use the stairs";

    //if(!stair[G]) cout << "use the stairs";
    //else cout << stair[G];
/*
    cout << endl;
    for(int i=1;i<11;i++)
    {
        cout << i << ": " << stair[i] << endl;
    }
*/

}