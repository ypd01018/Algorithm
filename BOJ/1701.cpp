#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string input;
int mx;
void make_pi(string b)
{
    int j=0,pi[5002]={0,};
    for(int i=1;i<b.size();i++)
    {
        while(j>0 && b[i]!=b[j]) j=pi[j-1];
        if(b[i]==b[j]) 
        {
            pi[i]=++j;
            mx = max(mx,pi[i]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> input;
    for(int i=0;i<input.size();i++)
    {
        string b = input.substr(i);
        make_pi(b);
    }
    cout << mx;
}