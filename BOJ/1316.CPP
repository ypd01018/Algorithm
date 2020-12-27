#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string a;
int N,idx[102],cnt;
void sol()
{
    cin >> a;
    for(int i=0;i<a.size();i++)
    {
        int alp = a[i]-'a';
        if(idx[alp]==-1)
        {
            idx[alp]=i;
            continue;
        }
        if(idx[alp]== i-1) idx[alp]=i;
        else return;
    }
    cnt++;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        a.clear();
        memset(idx,-1,sizeof(idx));
        sol();
    }
    cout << cnt;
}