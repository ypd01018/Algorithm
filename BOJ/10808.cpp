#include<iostream>
#define endl '\n' 
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    char my[100];
    cin>>s; 
    for (char i='a' ; i<='z' ; i++ )
    {
        int cnt=0;
        for(auto j : s)
        {
            if(i == j) cnt++;
        }
       cout << cnt <<" ";
       
    }

    
}