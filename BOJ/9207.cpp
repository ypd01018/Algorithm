#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int T;
char mat[5][9];
int sol()
{
    for(int i=0;i<5;i++)
    {
        string a; cin >> a;
        for(int j=0;j<9;j++) mat[i][j]=a[j];
    }
    
}
int main()
{
    cin >> T;
    for(int i=0;i<T;i++) cout << sol() << endl;
}