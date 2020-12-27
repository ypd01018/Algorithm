#include <string>
#include <vector>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
set<string> s;
int mn=999999,mx;

bool equal(string target,int n)
{
    for(int i=0;i+n<target.size();i++)
    {
        string a = "";
        for(int j=0;j<n;j++)
        {
            a.push_back(target[j]);
        }
        if(s.count(a)) return true;
    }
    return false;
}
bool solution(vector<string> phone_book) 
{
    bool answer = true;
    for(int i=0;i<phone_book.size();i++)
    {
        s.insert(phone_book[i]);
        mn = min(mn,(int)phone_book[i].size());
        mx = max(mn,(int)phone_book[i].size());
    }

    for(int i=0;i<phone_book.size();i++)
    {
        for(int j=mn;j<=mx;j++)
        {
            if(equal(phone_book[i],j)) return false;
        }
    }
    
    return true;
}

int main()
{
    int N; cin >> N;
    vector<string> v;
    for(int i=0;i<N;i++)
    {
        string a; cin >> a; 
        v.push_back(a);
    }
    cout << solution(v);
}