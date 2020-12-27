#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int T,N;
string arr[10'002];
unordered_map<string,int> um;
void sol()
{
    um.clear();
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
        um[arr[i]]=1;
    }
    for(int i=0;i<N;i++)
    {
        string a="";
        for(int j=0;j<arr[i].size()-1;j++)
        {
            a.push_back(arr[i][j]);
            if(um[a])
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> T;
    for(int i=0;i<T;i++) sol();
}
