#include<iostream>
#define endl "\n"
using namespace std;
int N;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin >> a >>b;
        cout << a+b << endl;
    }
}