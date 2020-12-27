#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string a,b;
int pi[1000002];
vector<int> v;
void getpi()
{
    int j = 0;
    for (int i = 1; i < b.size(); i++)
    {
        while (j > 0 && b[i] != b[j]) j = pi[j - 1];      
        if (b[i] == b[j]) pi[i] = ++j;        
    }
}
void kmp()
{
    int j = 0;
    for (int i = 0; i < a.size(); i++)
    {
        while (j > 0 && a[i] != b[j]) j = pi[j - 1];  
        if (a[i] == b[j])
        {         
            if (j == b.size() - 1)
            {  
                v.push_back(i - b.size() + 2);
                j = pi[j];  
            }
            else j++; 
        }
    }
}

int main()
{
    getline(cin,a);
    getline(cin,b);
    getpi();
    kmp();
    cout << v.size()<<endl;
    for(int i : v) cout << i << endl;

}