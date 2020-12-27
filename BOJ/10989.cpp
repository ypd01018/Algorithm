#include<iostream>
#define endl "\n"
using namespace std;
short cnt[10001];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int N;short a;
    cin >> N;
    for(int i=0;i<N;i++) 
    {
        cin >> a; cnt[a]++;
    }
    for(int i=1;i<=10'000;i++)
    {
        if(cnt[i])
        for(int j=0;j<cnt[i];j++) 
        {
            cout << i << endl;
        }
    }

}