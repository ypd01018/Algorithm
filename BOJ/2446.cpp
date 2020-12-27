#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N;
vector<string> v;
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        string a;
        for(int j=0;j<i;j++) a.push_back(' ');
        for(int j=i;j<-1*i+2*N-1;j++) a.push_back('*');
        v.push_back(a);
    }
    for(int i=0;i<v.size();i++) cout <<v[i] << endl;
    for(int i=v.size()-2;i>=0;i--) 
    {
        cout << v[i];
        if(i) cout << endl;
    }
}