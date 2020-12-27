#include<iostream>
#define endl "\n"
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    int n,x,y,v;
    double d;
    vector<pair<double,int>> turn;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y >> v;
        d=(sqrt(x*x + y*y) / v);
        turn.push_back( make_pair(d,i+1) );
    }

    sort(turn.begin(),turn.end());

    for(int i=0;i<n;i++)
    {
        cout << turn[i].second << endl;
    }

}