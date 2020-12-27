#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,K;
string num;
vector<char> v;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> K >> num;
    for(int i=0;i<num.size();i++)
    {
        while(!v.empty() && v.back()<num[i] && K)
        {
            v.pop_back();
            K--;
        }    
        v.push_back(num[i]);
    }
    for(int i=0;i<v.size()-K;i++) cout << v[i];
}   