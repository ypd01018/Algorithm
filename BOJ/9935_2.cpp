#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string a,b;
list<char> lst;
bool flag = true;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    for(int i=0;i<a.size();i++)
    {
        lst.push_back(a[i]);
    }
    list<char>::iterator iter=lst.begin();
    while(iter != lst.end())
    {
        if(*iter==b[0])
        {
            bool check=true; list<char>::iterator cache = iter;
            for(int i=0;i<b.size();i++)
            {
                if(iter==lst.end() ||(*iter)!=b[i]){check = false; break;}
                iter++;
            }
            iter = cache;
            if(check) 
            {
                for(int i=0;i<b.size();i++) iter = lst.erase(iter);
                for(int i=0;i<b.size() && iter!=lst.begin();i++) iter--; 
                continue;
            }
        }
        iter++;        
    }
    if(lst.size()) for(iter = lst.begin();iter!=lst.end();iter++) cout << *iter;
    else cout << "FRULA";
}