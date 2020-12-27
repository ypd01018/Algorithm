#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int T;
void sol()
{
    string input;
    int arr[55],flag=1;
    cin >> input;
    for(int i=0;i<input.size();i++)
    {
        arr[i] = input[i]-'0';
    }

    for(int i=0;i<input.size();i++)
    {
        if(arr[i]==flag%2)
        {
            flag++;
        }
    }
    cout << flag-1;
    
    
}
int main()
{
    cin >> T;
    for(int i=1;i<=T;i++)
    {
        cout << '#' << i <<' ';
        sol();
        cout << endl;
    }
}