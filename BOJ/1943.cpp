#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> coin;
int N;

void sol()
{
    set<int> m[2];
    coin.clear();
    
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int n,val;
        cin >> val >> n;
        for(int j=0;j<n;j++)
        {
            coin.push_back(val);//최대 10만
        }
    }
    m[0].insert(coin[0]); m[0].insert(-1*coin[0]);

    set<int>::iterator j;

    for(int i=1;i<coin.size();i++)
    {
        for(j=m[(i+1)%2].begin();j!=m[(i+1)%2].end();j++)
        {
            int val = *j;
            m[(i+2)%2].insert(val+coin[i]); m[(i+2)%2].insert(val-coin[i]);
        }
        m[(i+1)%2].clear();
    }

    j=m[(coin.size()+1)%2].find(0);
    if(j==m[(coin.size()+1)%2].end()) cout << 0;
    else cout << 1;
    cout << endl;
}

int main()
{
    for(int i=0;i<3;i++) sol();
}